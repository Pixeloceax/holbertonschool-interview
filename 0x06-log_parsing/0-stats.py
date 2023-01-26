#!/usr/bin/python3
"""Script that reads stdin line by line and computes metrics"""
from sys import stdin

total_size = 0
status_codes = {code: 0 for code in [
    "200", "301", "400", "401", "403", "404", "405", "500"]}


def print_():
    """Prints the metrics"""
    print("File size: {}".format(total_size))
    for status, count in sorted(status_codes.items()):
        if count != 0:
            print("{}: {}".format(status, count))


try:
    for i, line in enumerate(stdin, start=1):
        matches = line.rstrip().split()
        try:
            status_code = matches[-2]
            file_size = matches[-1]
            if status_code in status_codes.keys():
                status_codes[status_code] += 1
            total_size.append(int(file_size))
        except Exception:
            pass
        if (i % 10 == 0):
            print_()
    print_()
except KeyboardInterrupt:
    print_()
    raise
