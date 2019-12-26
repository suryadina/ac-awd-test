%PEMBANGKIT SAMPLE 64 DAN YANG  KELIPATAN 32 BIT
function[X]=GENSAMPLE(jumlah_sampel,ukuran_sampel);
%BUKA FILE OUTPUT
fid = fopen('C:\Users\0807100754\Desktop\SAMPLE.txt', 'wt');
%SELESAI MEMBUKA FILE OUTPUT

%MULAI MEMBANGKITKAN SAMPLE
for X = 1:jumlah_sampel
    sample= randi([0,2^32],1,(ukuran_sampel/32));
    fprintf(fid,'%08x', sample);
    fprintf(fid,'\n');
end 
%SELESAI MEMBANGKITKAN SAMPLE

%MENUTUP FILE
status = fclose(fid);
if status==-1
    disp('file tidak bisa ditutup')
end
X = 'selesai'
%SELESAI MENUTUP FILE