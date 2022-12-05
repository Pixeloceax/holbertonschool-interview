#!/usr/bin/python3
"""
    0-lockboxes
"""
def canUnlockAll(boxes):
    """
        boxes: list of lists
    """
    if boxes is None or len(boxes) == 0:
        return False
    key = [0]
    for K in key:
        for B in boxes[K]:
            if B not in key and B < len(boxes):
                key.append(B)
    if len(key) == len(boxes):
        return True
    return False
