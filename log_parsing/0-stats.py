#!/usr/bin/python3
"""
Script that reads stdin line by line and computes metrics
"""

import sys

ALLOWED_STATUS = {200, 301, 400, 401, 403, 404, 405, 500}


def print_stats(total_size, status_counts):
    """Print the current statistics."""
    print("File size: {}".format(total_size))
    for code in sorted(status_counts.keys()):
        count = status_counts[code]
        if count:
            print("{}: {}".format(code, count))


def main():
    total_size = 0
    status_counts = {code: 0 for code in ALLOWED_STATUS}
    line_count = 0

    try:
        for line in sys.stdin:
            line = line.strip()
            if not line:
                continue
            parts = line.split()

            try:
                file_size = int(parts[-1])
                status = int(parts[-2])
            except (IndexError, ValueError):
                # Skip lines with format errors.
                continue

            total_size += file_size
            if status in ALLOWED_STATUS:
                status_counts[status] += 1

            line_count += 1
            if line_count % 10 == 0:
                print_stats(total_size, status_counts)
    except KeyboardInterrupt:
        print_stats(total_size, status_counts)
        sys.exit(0)

    print_stats(total_size, status_counts)


if __name__ == "__main__":
    main()
