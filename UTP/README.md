# UTP SOK PTI 2024

## Soal

[Link Soal](https://s.ub.ac.id/utpsokpti24aklwid)

## Kunci Jawaban

1. [Kesoku Band](#kesoku-band)
2. [Cek Tugas](#cek-tugas)
3. [Misi Rahasia](#misi-rahasia)
4. [Organisasi Proyek Perangkat Lunak](#organisasi-proyek-perangkat-lunak)
5. [Analisis Proses](#analisis-proses)
6. [Say The Name](#say-the-name)

### Kesoku Band

```zsh
sudo su
adduser bocchi  # run as root
adduser ryo  # run as root
groupadd kesokuband # run as root
usermod -aG kesokuband bocchi # run as root
usermod -aG kesokuband ryo # run as root
mkdir -p /home/kesokuband/lyrics/ # run as root
chown :kesokuband /home/kesokuband/lyrics # run as root
touch /home/kesokuband/lyrics/lyrics.txt # run as root
chown bocchi:kesokuband /home/kesokuband/lyrics/lyrics.txt # run as root
chmod 070 /home/kesokuband/lyrics # run as root
chmod 740 /home/kesokuband/lyrics/lyrics.txt # run as root
su bocchi
nano /home/kesokuband/lyrics/lyrics.txt # run as bocchi 
su ryo
cat /home/kesokuband/lyrics/lyrics.txt # run as ryo
su bocchi 
# Bikin 20 file dgn nama lyrics1.txt hingga lyrics20.txt dngn isi yang sama dgn file lyrics.txt, caranya bebas salah satu caranya adalah bash scripting 
for i in {1..20}; do touch /home/kesokuband/lyrics/lyrics$i.txt; cat /home/kesokuband/lyrics/lyrics.txt > /home/kesokuband/lyrics/lyrics$i.txt; done; # run as bocchi 
rm /home/kesokuband/lyrics/lyrics.txt # run as bocchi 
su ryo
yes # run as ryo
kill $PID # run as root
echo Minasan, Yoku Yarimashita # run as root
```

### Cek Tugas

```zsh
ps -u ryo
pstree
top # bisa htop juga
kill $PID
```

### Misi Rahasia 

```zsh
touch /laporan_rahasia.txt
ls -l /laporan_rahasia.txt
adduser agen
groupadd rahasia
usermod -aG rahasia agen
sudo chown agen:rahasia /laporan_rahasia
mkdir /rahasia
chmod 700 /rahasia
cp /laporan_rahasia.txt /rahasia/laporan_terenkripsi.txt
mv /rahasia/laporan_terenkripsi.txt /.rahasia/laporan_final.txt
rm /laporan_rahasia.txt
rm /rahasia1. 
```

### Organisasi Proyek Perangkat Lunak

```zsh
mkdir Kode Dokumen Konfigurasi
mv *.java Kode
mv *.docx Dokumen
mv *.conf Konfigurasi
cp Konfigurasi/file.config Konfigurasi/file_copy.config
ls Kode
ls Dokumen
ls Konfigurasi
```

### Analisis Proses

```zsh
yes SUKSES UTP SOK
pstree
killall yes
```

### Say The Name

```zsh
touch catatan.txt
nano catatan.txt
cat catatan.txt
rm catatan.txt
```