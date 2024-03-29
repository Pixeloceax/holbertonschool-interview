#!/usr/bin/python3
"""
Module for validUTF8 method
"""


def validUTF8(data):
    """
    Method that determines if a
    given data set represents a valid UTF-8 encoding
    """
    num_bytes_to_follow = 0
    for byte in data:
        if num_bytes_to_follow == 0:
            if byte >> 7 == 0:
                num_bytes_to_follow = 0
            elif byte >> 5 == 0b110:
                num_bytes_to_follow = 1
            elif byte >> 4 == 0b1110:
                num_bytes_to_follow = 2
            elif byte >> 3 == 0b11110:
                num_bytes_to_follow = 3
            else:
                return False
        else:
            if byte >> 6 != 0b10:
                return False
            num_bytes_to_follow -= 1
    return num_bytes_to_follow == 0
