#!/bin/bash

> test_result.txt

test_count=0

# 100 test çalıştır
for i in {1..100}; do
    # Sıralı dizi oluştur (1-100)
    SORTED=($(seq 1 100))
    
    # Shuffle et (çok az karıştır - disorder'ı kontrol altında tut)
    # Fisher-Yates shuffle ile random pozisyon değişişimi yap
    for ((j = 0; j < 5; j++)); do
        idx1=$((RANDOM % 100))
        idx2=$((RANDOM % 100))
        # Swap
        temp=${SORTED[$idx1]}
        SORTED[$idx1]=${SORTED[$idx2]}
        SORTED[$idx2]=$temp
    done
    
    INPUT="${SORTED[@]}"
    
    # Disorder hesapla
    DISORDER=$(./push_swap $INPUT 2>&1 | grep -oE '0\.[0-9]+' | head -1)
    
    # Boş ya da sıfırsa atla
    if [ -z "$DISORDER" ] || [ "$DISORDER" = "0" ]; then
        continue
    fi
    
    # Disorder <= 0.2 ise test et
    if (( $(echo "$DISORDER <= 0.2" | bc -l) )); then
        OPERATIONS=$(./push_swap $INPUT 2>/dev/null | wc -l)
        RESULT=$(./push_swap $INPUT 2>/dev/null | ./checker_linux $INPUT)
        
        if [ "$RESULT" = "OK" ]; then
            echo "Test $((test_count+1)): PASS - Operations: $OPERATIONS - Disorder: $DISORDER" >> test_result.txt
            STATUS="✓ PASS"
        else
            echo "Test $((test_count+1)): FAIL - Operations: $OPERATIONS - Disorder: $DISORDER" >> test_result.txt
            STATUS="✗ FAIL"
        fi
        
        echo "Test $((test_count+1)): $STATUS | Ops=$OPERATIONS | Disorder=$DISORDER"
        ((test_count++))
    fi
done

echo ""
echo "============================================"
echo "Total tests: $test_count/100"
echo "Results saved to test_result.txt"
echo "============================================"
cat test_result.txt