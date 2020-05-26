#!/usr/bin/env python3
""" Imports """
import sys
import os


def get_heap(pid):
    """ READ /proc/[pid]/maps file
    """
    pathname = "/proc/{}/maps".format(pid)
    try:
        with open(pathname, 'r') as maps:
            """ Open file maps of the process
            """
            while True:
                mapping = maps.readline()
                if not mapping:
                    sys.exit(-1)
                if mapping[-8:] == ' [heap]\n':
                    print("[*] Found [heap]:")
                    mapping = mapping.split()
                    print("\tpathname = {}".format(mapping[5]))
                    print("\taddresses = {}".format(mapping[0]))
                    print("\tpermisions = {}".format(mapping[1]))
                    print("\toffset = {}".format(mapping[2]))
                    print("\tinode = {}".format(mapping[4]))
                    addresses = mapping[0].split('-')
                    addr_start = int(addresses[0], 16)
                    addr_end = int(addresses[1], 16)
                    print("[*] Addr start [{}] | end [{}]"
                          .format(addresses[0].lstrip('0x'),
                                  addresses[1].lstrip('0x')))
                    return (addr_start, addr_end)
    except Exception as e:
        sys.exit(-1)


def main():
    """ Capture args and write process
    """
    arg_count = len(sys.argv)
    print(arg_count)

    if arg_count <= 3:
        print("Usage: read_write_heap.py pid search_string replace_string")
        sys.exit(-1)

    pid = sys.argv[1]
    word = sys.argv[2]
    new_word = sys.argv[3]

    pathname = "/proc/{}/mem".format(pid)

    print("[*] maps: /proc/{}/maps".format(pid))
    print("[*] mem: {}".format(pathname))
    heap_start, heap_end, = get_heap(pid)

    with open(pathname, 'r+b') as mem:
        """ Open file mem of the process
        """
        mem.seek(heap_start)
        heap = mem.read(heap_end - heap_start).decode("ISO-8859-1")
        offset = heap.find(word)

        if offset == -1:
            sys.exit(offset)
#            sys.exit("ERROR '{}' not found in heap.".format(word))
        print("[*] Found '{}' at {}".format(word, offset))
        addr_rep = heap_start + offset
        print("[*] Writing '{}' at {}".format(new_word,
              hex(addr_rep).lstrip('0x')))

        mem.seek(heap_start + offset)
        mem.write(new_word.encode("ISO-8859-1"))


if __name__ == '__main__':
    main()