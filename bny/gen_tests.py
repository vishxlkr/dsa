import json, random, time, os

PROB_PATH = r".cph\.3.cpp_4b3e84b4861c014e0d9b4dfb261533d1.prob"

# ── Brute-force oracle ───────────────────────────────────────────────────────
def oracle(s):
    n = len(s)
    solutions = []
    for mask in range(1 << n):
        p = [(mask >> i) & 1 for i in range(n)]
        ok = all(
            (p[(i-1)%n] ^ p[i] ^ p[(i+1)%n]) == int(s[i])
            for i in range(n)
        )
        if ok:
            solutions.append("".join(map(str, p)))
    if not solutions:
        return "No Chance"
    if len(solutions) > 1:
        return "Multiple Scenario"
    return solutions[0]

# ── Generate diverse test cases ──────────────────────────────────────────────
rng = random.Random(42)
cases = []

# All length-1 edge cases
for b in "01":
    cases.append(b)

# All length-2 and length-3 strings
for n in range(2, 4):
    for mask in range(1 << n):
        cases.append(format(mask, f'0{n}b'))

# Random strings for lengths 4..18
for n in range(4, 19):
    for _ in range(4):
        cases.append("".join(rng.choice("01") for _ in range(n)))

# A handful of longer random strings (still feasible for oracle up to n=20)
for n in [19, 20]:
    for _ in range(6):
        cases.append("".join(rng.choice("01") for _ in range(n)))

# Remove duplicates while preserving order
seen = set()
unique_cases = []
for c in cases:
    if c not in seen:
        seen.add(c)
        unique_cases.append(c)

# ── Build CPH test-case entries ──────────────────────────────────────────────
new_tests = []
base_id = int(time.time() * 1000)
for i, inp in enumerate(unique_cases):
    out = oracle(inp)
    new_tests.append({
        "id": base_id + i,
        "input": inp,
        "output": out
    })

print(f"Generated {len(new_tests)} test cases.")

# Print summary
counts = {"No Chance": 0, "Multiple Scenario": 0, "unique": 0}
for t in new_tests:
    if t["output"] == "No Chance":
        counts["No Chance"] += 1
    elif t["output"] == "Multiple Scenario":
        counts["Multiple Scenario"] += 1
    else:
        counts["unique"] += 1
print(f"  No Chance:         {counts['No Chance']}")
print(f"  Multiple Scenario: {counts['Multiple Scenario']}")
print(f"  Unique solution:   {counts['unique']}")

# ── Update .prob file ────────────────────────────────────────────────────────
with open(PROB_PATH, "r", encoding="utf-8") as f:
    prob = json.load(f)

prob["tests"] = new_tests

with open(PROB_PATH, "w", encoding="utf-8") as f:
    json.dump(prob, f)

print(f"\nUpdated: {PROB_PATH}")
