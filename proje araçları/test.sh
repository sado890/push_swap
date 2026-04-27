#!/bin/bash

# Sonuç dosyası
RESULT_FILE="test_result.txt"
> $RESULT_FILE

# Test fonksiyonu
run_test() {
    SIZE=$1
    LIMIT=$2
    ITERATIONS=20 # İstersen 100'e çıkarabilirsin
    
    echo "--- $SIZE Input için testler başlıyor (Limit: $LIMIT) ---" >> $RESULT_FILE
    
    # Disorder kontrolünü daha iyi yönetmek için değişken tanımla
SWAP_COUNT=5 
# Eğer disorder çok yüksek çıkıyorsa bu sayıyı düşür, 
# tam tersi ise artırarak rastgeleliği değiştirebilirsin.

	for ((j = 0; j < SWAP_COUNT; j++)); do
    	idx1=$((RANDOM % 100))
    	idx2=$((RANDOM % 100))
		while [ "$idx1" -eq "$idx2" ]; do
        idx2=$((RANDOM % 100))
    	done
    	temp=${SORTED[$idx1]}
    	SORTED[$idx1]=${SORTED[$idx2]}
    	SORTED[$idx2]=$temp
	done
}

# Testleri Çalıştır
run_test 100 2000#!/bin/bash

# Renk kodları
GREEN='\033[0;32m'
RED='\033[0;31m'
NC='\033[0m' # No Color

echo "Testler başlıyor..."

for i in {1..20}; do
    # 100 adet benzersiz rastgele sayı üret
    ARG=$(shuf -i 1-500 -n 100 | tr '\n' ' ')
    
    # 1. Önce Düzensizliği (Disorder) hesapla
    # Kendi programında disorder'ı stdout'a yazdıran bir fonksiyonun olduğunu varsayıyorum
    # Eski satır: DISORDER=$(./push_swap $ARG | grep "Disorder" | cut -d' ' -f2)
	# Yeni satır:
	DISORDER=$(./push_swap $ARG | head -n 1)
    # 2. İşlem sayısını al
    OPS=$(./push_swap $ARG | wc -l)
    
    # 3. Sonucu doğrula (checker_linux ile)
    CHECK=$(./push_swap $ARG | ./checker_linux $ARG)
    
    if [ "$CHECK" == "OK" ]; then
        echo -e "Test $i: ${GREEN}PASS${NC} | Disorder: $DISORDER | Ops: $OPS"
    else
        echo -e "Test $i: ${RED}FAIL${NC} | Input: $ARG"
        break
    fi
done
run_test 500 12000

echo "Testler tamamlandı. Detaylar 'test_result.txt' dosyasında."