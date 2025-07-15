import re

filename = input("filename : ")

with open(filename+".txt", "r") as file:
    lines = file.readlines()

hop_pattern = re.compile(r"Hops from \d+ to \d+ = (\d+)")
hop_counts = [int(m.group(1)) for line in lines if (m := hop_pattern.search(line))]

if not hop_counts:
    print("No hop data found.")
else:
    total = sum(hop_counts)
    avg = total / len(hop_counts)
    print(f"Total hops: {total}")
    print(f"Average hops per pair: {avg:.2f}")
