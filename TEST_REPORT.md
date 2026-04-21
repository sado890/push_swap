# Push_Swap Test Raporu

## ✅ Derleme Durumu
- **Makefile**: Oluşturuldu ✓
- **Derleme**: Başarılı ✓
- **Tüm Dosyalar**: Derlenmiş ✓

---

## ✅ 1. HATA YÖNETİMİ TESTLERI (Çıktı: Error)

| Test | Komut | Sonuç |
|------|-------|-------|
| 1. Boş giriş | `./push_swap ""` | ❌ Error ✓ |
| 2. Sadece boşluk | `./push_swap "    "` | ❌ Error ✓ |
| 3. Mükerrer sayılar | `./push_swap 1 2 3 1` | ❌ Error ✓ |
| 4. Mükerrer sayılar (tırnaklı) | `./push_swap "5 10 15" "10"` | ❌ Error ✓ |
| 5. Geçersiz karakter (1 2 3a 4) | `./push_swap 1 2 3a 4` | ❌ Error ✓ |
| 6. Geçersiz karakter (1 2 - 4) | `./push_swap "1 2 - 4"` | ❌ Error ✓ |
| 7. Ondalık sayı | `./push_swap 1.5 2` | ❌ Error ✓ |
| 8. Integer Overflow | `./push_swap 2147483648` | ❌ Error ✓ |
| 9. Integer Underflow | `./push_swap -2147483649` | ❌ Error ✓ |
| 10. Çok büyük sayı | `./push_swap 99999999999999` | ❌ Error ✓ |
| 11. Sadece + işareti | `./push_swap +` | ❌ Error ✓ |
| 12. Sadece - işareti | `./push_swap -` | ❌ Error ✓ |
| 13. İşaret içinde | `./push_swap "1 + 2"` | ❌ Error ✓ |

**Sonuç**: 13/13 ✅ BAŞARILI

---

## ✅ 2. GEÇERLI GİRİŞ TESTLERI (Çıktı: A: ...)

| Test | Komut | Çıktı | Sonuç |
|------|-------|-------|-------|
| 1. Negatif ve pozitif | `./push_swap -5 10 -100 0 42` | A: -5 10 -100 0 42 | ✓ |
| 2. Tırnaklı ve ayrı | `./push_swap "1 2 3" 4 "5 6" 7` | A: 1 2 3 4 5 6 7 | ✓ |
| 3. Önünde sıfır | `./push_swap 001 0002 05` | A: 1 2 5 | ✓ |
| 4. Min ve Max | `./push_swap -2147483648 2147483647` | A: -2147483648 2147483647 | ✓ |
| 5. Tek argüman | `./push_swap 42` | A: 42 | ✓ |

**Sonuç**: 5/5 ✅ BAŞARILI

---

## ✅ 3. SINIIR TESTLERI

| Test | Komut | Çıktı | Sonuç |
|------|-------|-------|-------|
| 1. Argümansız | `./push_swap` | (no output) | ✓ |

**Sonuç**: 1/1 ✅ BAŞARILI

---

## ✅ 4. BELLEK SIZZINTISI TESTLERI (Valgrind)

| Test | Komut | Sonuç |
|------|-------|-------|
| 1. Başarılı durum | `valgrind ./push_swap 1 2 3 4 5 6` | ✓ Bellek sızıntısı YOK |
| 2. Mükerrer sayılar | `valgrind ./push_swap 1 2 2 3` | ✓ Bellek sızıntısı YOK |
| 3. Geçersiz karakter | `valgrind ./push_swap "1 2 a"` | ✓ Bellek sızıntısı YOK |

**Sonuç**: 3/3 ✅ BAŞARILI (Tüm bellek düzgün serbest bırakıldı)

---

## 📊 GENEL ÖZET

```
Toplam Test: 22
Başarılı: 22 ✅
Başarısız: 0 ❌
Başarı Oranı: 100%
```

### Kategoriler:
- Hata Yönetimi: 13/13 ✅
- Geçerli Giriş: 5/5 ✅
- Sınır Testleri: 1/1 ✅
- Bellek Testleri: 3/3 ✅

---

## 🎯 Sonuç: ✅ TÜM TESTLER BAŞARILI!

Proje tüm gereklilik testlerini başarıyla geçmiştir.
- ✅ Hata yönetimi mükemmel
- ✅ Geçerli giriş doğru işleniyor
- ✅ Bellek yönetimi kusursuz
- ✅ Sınır koşulları handled
