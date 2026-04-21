#!/usr/bin/env python3
import subprocess
import random

tests = [
    ("Çoklu İşaret (++1)", './push_swap "++1" 2', "Error"),
    ("İşaret Sonrası Boşluk (+ 1)", './push_swap "+ 1" 2', "Error"),
    ("Sayı Arası Çoklu Boşluk", './push_swap "1      2" 3', "A:"),
    ("Başta/Sonda Boşluk", './push_swap "  1 2  " " 3 "', "A:"),
    ("Min/Max tam sınır", './push_swap -2147483648 2147483647', "A:"),
    ("Uzun sıfırlar", './push_swap 000000000000000000001', "A:"),
    ("Limit üstü uzunluk", './push_swap 999999999999999999999999999999', "Error"),
    ("Boş argüman kombinasyonu", './push_swap "1 2" "" "3"', "Error"),
    ("Sadece boşluk", './push_swap "   "', "Error"),
    ("Çoklu tırnak iç mükerrer", './push_swap "1 2 3" "4 5 5"', "Error"),
    ("Sıfırın mükerrerliği (0 -0 +0)", './push_swap 0 -0 +0', "Error"),
    ("Hatalı sıfır (00 0)", './push_swap 00 0', "Error"),
    ("Çift eksi (--1)", './push_swap --1', "Error"),
    ("Tab karakteri", 'printf "1\\t2" | xargs ./push_swap', "A:"),
    ("Non-ASCII karakter", './push_swap "1 ² 3"', "Error"),
]

passed = 0
failed = 0
results = []

for name, cmd, expected in tests:
    try:
        result = subprocess.run(cmd, shell=True, capture_output=True, text=True, timeout=5)
        output = (result.stdout + result.stderr).strip()
        
        if expected in output:
            results.append((name, True, ""))
            passed += 1
        else:
            results.append((name, False, f"Beklenen: {expected}, Aldı: {output[:40]}"))
            failed += 1
    except Exception as e:
        results.append((name, False, str(e)[:40]))
        failed += 1

# 500 Sayı Testi
try:
    numbers = list(range(-250, 251))
    random.shuffle(numbers)
    arg_str = " ".join(map(str, numbers))
    cmd = f'./push_swap {arg_str}'
    result = subprocess.run(cmd, shell=True, capture_output=True, text=True, timeout=5)
    output = (result.stdout + result.stderr).strip()
    
    if "A:" in output:
        results.append(("500 karışık sayı", True, ""))
        passed += 1
    else:
        results.append(("500 karışık sayı", False, output[:40]))
        failed += 1
except:
    results.append(("500 karışık sayı", False, "Exception"))
    failed += 1

with open("test_results.txt", "w") as f:
    for name, status, msg in results:
        status_str = "✓" if status else "✗"
        f.write(f"{status_str} {name}")
        if msg:
            f.write(f" ({msg})")
        f.write("\n")
    f.write(f"\nToplam: {passed + failed} | Başarılı: {passed} | Başarısız: {failed}\n")
    f.write(f"Başarı Oranı: {passed*100//(passed+failed)}%\n")

print("Test sonuçları test_results.txt dosyasına yazıldı")
for name, status, msg in results:
    status_str = "✓" if status else "✗"
    print(f"{status_str} {name}")
print(f"\nToplam: {passed + failed} | Başarılı: {passed} | Başarısız: {failed}")
