function [ m ] = Ucitaj_podatke(url)

    tekst_podatci = urlread(url);
    tmp = textscan(tekst_podatci,'%f %f %f %f %f %f %f %f %*q','TreatAsEmpty','?', 'CollectOutput',1);
    m = tmp{1};
    
    redak_ima_nan = isnan(m(:,4));
    m(redak_ima_nan,4) = mean(m(~redak_ima_nan,4));
    
end