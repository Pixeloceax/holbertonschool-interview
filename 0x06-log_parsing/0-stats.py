#!/usr/bin/python3
"""Script that reads stdin line by line and computes metrics"""
from sys import stdin


def process_log_line(line: str, metrics: dict) -> None:
    """Process a single log line and update the metrics"""
    try:
        args = line.strip().split(" ")
        if len(args) == 9:
            status = args[-2]
            if status in metrics['status_codes']:
                metrics['status_codes'][status] += 1
            metrics['total_size'] += int(args[-1])
            metrics['count'] += 1
    except ValueError:
        raise ValueError("Invalid log line format")


def print_metrics(metrics: dict) -> None:
    """Print the computed metrics"""
    print("File size: {}".format(metrics['total_size']))
    for status, count in sorted(metrics['status_codes'].items()):
        if count != 0:
            print("{}: {}".format(status, count))


def main():
    """Main function"""
    metrics = {
        'total_size': 0,
        'status_codes': {code: 0 for code in ["200", "301", "400", "401",
                                              "403", "404", "405", "500"]},
        'count': 0
    }
    for line in stdin:
        process_log_line(line, metrics)
        if metrics['count'] % 10 == 0:
            print_metrics(metrics)
    print_metrics(metrics)


if __name__ == "__main__":
    main()
