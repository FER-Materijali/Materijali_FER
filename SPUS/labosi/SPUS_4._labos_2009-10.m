%% Zadatak 1.1 
% SNR SIGNALA

% SIGNAL 1
% Niz brojeva raspodjeljen po Gaussovoj razdiobi
% s ocekivanjem 0 i varijancom 25

    x = sqrt(25) * randn(1000,1);
    Px = mean(x.^2);  % snaga nekvantiziranog signala

    for i=1:16
        Qx(:,i) = kvantiziraj(x,2^i);
        ex(:,i) = Qx(:,i) - x;  % sum kvantizacije
        Pex(i) = mean(ex(:,i).^2);  % snaga suma kvantizacije
        SNRx(i) = 10*log10(Px/Pex(i));
    end

% SIGNAL 2
% Niz brojeva jednoliko raspodjeljen na intervalu 
% od -10 do 10

    y = -10 + (10 + 10) * rand(1000,1);
    Py = mean(y.^2);  % snaga nekvantiziranog signala

    for i=1:16
        Qy(:,i) = kvantiziraj(y,2^i);
        ey(:,i) = Qy(:,i) - y;  % sum kvantizacije
        Pey(i) = mean(ey(:,i).^2);  % snaga suma kvantizacije
        SNRy(i) = 10*log10(Py/Pey(i));
    end

% SIGNAL 3
% Sinus amplitude 10

    pom = [0:0.1:99.9];
    z = 10 * sin(pom);
    z = z';
    Pz = mean(z.^2);  % snaga nekvantiziranog signala

    for i=1:16
        Qz(:,i) = kvantiziraj(z,2^i);
        ez(:,i) = Qz(:,i) - z;  % sum kvantizacije
        Pez(i) = mean(ez(:,i).^2);  % snaga suma kvantizacije
        SNRz(i) = 10*log10(Pz/Pez(i));
    end

% PLOT signals

    t = [1:16];
    plot(t, SNRx, 'r', t, SNRy, 'g', t, SNRz, 'b');
    legend('Gaussov', 'Jednoliko', 'Sinus');
    
    
%% Zadatak 1.2
% SNR GLASOVNOG SIGNALA

% ucitavanje signala
    [x, fs, nbits]=wavread('glas.wav');
    
% izracun SNR
    Px = mean(x.^2);  % snaga nekvantiziranog signala

    for i=1:16
        Qx(:,i) = kvantiziraj(x,2^i);
        soundsc(Qx(:,i),fs);  % poslusaj kvantizirani signal
        ex(:,i) = Qx(:,i) - x;  % sum kvantizacije
        Pex(i) = mean(ex(:,i).^2);  % snaga suma kvantizacije
        SNRx(i) = 10*log10(Px/Pex(i));
    end
    
    plot(SNRx);
    
%% Zadatak 2.3
% KUMULATIVNI HISTOGRAM

% SIGNAL 1
    x = sqrt(25) * randn(1000,1); 
    
    nx = length(x);  % suma vrijednosti signala
    pomx = linspace(min(x), max(x), 256); 
    
    subplot(2,1,1), bar(cumsum(hist(x, pomx)));  % kumulativni histogram
    subplot(2,1,2), bar(cumsum(hist(x, pomx))/nx);  % slalirani kumulativni histogram

% SIGNAL 2
    y = -10 + (10 + 10) * rand(1000,1);
    
    ny = length(y);  % suma vrijednosti signala
    pomy = linspace(min(y), max(y), 256); 
    
    subplot(2,1,1), bar(cumsum(hist(y, pomy)));  % kumulativni histogram
    subplot(2,1,2), bar(cumsum(hist(y, pomy))/ny);  % slalirani kumulativni histogram

% SIGNAL 3
    pom = [0:0.1:99.9];
    z = 10 * sin(pom);
    z = z';
    
    nz = length(z);  % suma vrijednosti signala
    
    pomz = linspace(min(z), max(z), 256);  
    subplot(2,1,1), bar(cumsum(hist(z, pomz)));  % kumulativni histogram
    subplot(2,1,2), bar(cumsum(hist(z, pomz))/nz);  % slalirani kumulativni histogram    


%% Zadatak 2.5 
% KOMPANDER

% SIGNAL 1
    x = sqrt(25) * randn(1000,1); 
    Px = mean(x.^2);  % snaga signala
    
    pomx = linspace(min(x), max(x), 1000)';
    [a, b] = hist(x, pomx);  % histogram
    Mx = cumsum(a);  % kumulativna suma - KOMPRESOR
    Mx = Mx/max(Mx); % fja distribucije
    out = normcdf(x, 0, 25);
    
    for i=1:8
        QMx(:,i) = kvantiziraj(out, 2^i, 0, 1);  % kvantizacija - KVANTIZACIJA
        
            % EKSPANZIJA
        Qx(:,i) = norminv(QMx(:,i), 0, 25);
        
             % SNR
        ex(:,i) = Qx(:,i) - x;  % sum kvantizacije
        Pex(i) = mean(ex(:,i).^2);  % snaga suma kvantizacije
        SNRx(i) = 10*log10(Px/Pex(i));
    end

% SIGNAL 2
    y = -10 + (10 + 10) * rand(1000,1);
    Py = mean(y.^2);  % snaga signala
    
    pomy = linspace(min(y), max(y), 1000)';
    [a, b] = hist(y, pomy);  % histogram
    My = cumsum(a);  % kumulativna suma - KOMPRESOR
    My = My/max(My); % fja distribucije
    out = unifcdf(y, -10, 10);
    
    for i=1:8
        QMy(:,i) = kvantiziraj(out, 2^i);  % kvantizacija - KVANTIZACIJA
        
            % EKSPANZIJA
        Qy(:,i) = unifinv(QMy(:,i), -10, 10);
        
             % SNR
        ey(:,i) = Qy(:,i) - y;  % sum kvantizacije
        Pey(i) = mean(ey(:,i).^2);  % snaga suma kvantizacije
        SNRy(i) = 10*log10(Py/Pey(i));
    end
    
% SIGNAL 3
    pom = [0:0.1:99.9];
    z = 10 * sin(pom);
    z = z';
    Pz = mean(z.^2);  % snaga signala
    
    pomz = linspace(min(z), max(z), 100)';
    [a, b] = hist(z, pomz);  % histogram
    Mz = cumsum(a);  % kumulativna suma - KOMPRESOR
    Mz = Mz/max(Mz); % fja distribucije
    out = interp1(b, Mz, z);
 
    k = 1;
    for i=1:length(Mz)
        if (Mz ~= 0)
            Mz_tmp(k) = Mz(i);
            k = k+1;
        end
    end
    
    clear Mz;
    Mz = Mz_tmp;
 
    for i=1:8
        QMz(:,i) = kvantiziraj(out, 2^i);  % kvantizacija - KVANTIZACIJA
        
            % EKSPANZIJA
        Qz(:,i) = interp1(Mz, b, QMz(:,i));
        
             % SNR
        ez(:,i) = Qz(:,i) - z;  % sum kvantizacije
        Pez(i) = mean(ez(:,i).^2);  % snaga suma kvantizacije
        SNRz(i) = 10*log10(Pz/Pez(i));
    end
    
% PLOT SNR
    t = [1:8];
    plot(t, SNRx, 'r', t, SNRy, 'g', t, SNRz, 'b');
    legend('Gaussov', 'Jednoliko', 'Sinus');
    
    
%% Zadatak 2.6 
% KOMPANDER GOVORNOG SIGNALA

% ucitavanje signala
    [z, fs, nbits]=wavread('glas.wav');
    Pz = mean(z.^2);

% kumulativni histogram
    nz = length(z);  % suma vrijednosti signala
    
    pomz = linspace(min(z), max(z), 256);  
    subplot(2,1,1), bar(cumsum(hist(z, pomz)));  % kumulativni histogram
    subplot(2,1,2), bar(cumsum(hist(z, pomz))/nz);  % slalirani kumulativni histogram

% kompander -> ekspander

    pomz = linspace(min(z), max(z), 100)';
    [a, b] = hist(z, pomz);  % histogram
    Mz = cumsum(a);  % kumulativna suma - KOMPRESOR
    Mz = Mz/max(Mz); % fja distribucije
    out = interp1(b, Mz, z);
 
    k = 1;
    for i=1:length(Mz)
        if (Mz ~= 0)
            Mz_tmp(k) = Mz(i);
            k = k+1;
        end
    end
    
    clear Mz;
    Mz = Mz_tmp;
 
    for i=1:8
        QMz(:,i) = kvantiziraj(out, 2^i);  % kvantizacija - KVANTIZACIJA
        
            % EKSPANZIJA
        Qz(:,i) = interp1(Mz, b, QMz(:,i));
        
             % SNR
        ez(:,i) = Qz(:,i) - z;  % sum kvantizacije
        Pez(i) = mean(ez(:,i).^2);  % snaga suma kvantizacije
        SNRz(i) = 10*log10(Pz/Pez(i));
    end
    
%% Zadatak 3.8 
% PROJEKTIRANJE LLOYDS-MAXOVOG KVANTIZATORA

% SIGNAL 1
    x = sqrt(25) * randn(1000,1); 
    Px = mean(x.^2);
    
    for i=1:8
        [px, cx] = lloyds(x, 2^i);
        [qx, Qx] = quantiz(x, px, cx);
        
        ex = Qx' - x;
        Pex = mean(ex.^2);
        SNRx(i) = 10*log10(Px/Pex);
    end   
    
% SIGNAL 2
    y = -10 + (10 + 10) * rand(1000,1);
     
    Py = mean(y.^2);
    
    for i=1:8
        [py, cy] = lloyds(y, 2^i);
        [qy, Qy] = quantiz(y, py, cy);
        
        ey = Qy' - y;
        Pey = mean(ey.^2);
        SNRy(i) = 10*log10(Py/Pey);
    end  

% SIGNAL 3
    pom = [0:0.1:99.9];
    z = 10 * sin(pom);
    z = z';
    
    Pz = mean(z.^2);
    
    for i=1:8
        [pz, cz] = lloyds(z, 2^i);
        [qz, Qz] = quantiz(z, pz, cz);
        
        ez = Qz' - z;
        Pez = mean(ez.^2);
        SNRz(i) = 10*log10(Pz/Pez);
    end  

% PLOT SNR
    t = [1:8];
    plot(t, SNRx, 'r', t, SNRy, 'g', t, SNRz, 'b');
    legend('Gaussov', 'Jednoliko', 'Sinus');

%% Zadatak 3.10

    [x, fs, nbits]=wavread('a13.wav');
    
    Px = mean(x.^2);
    
    for i=1:8
        [px, cx] = lloyds(x, 2^i);
        [qx, Qx] = quantiz(x, px, cx);
        
        ex = Qx' - x;
        Pex = mean(ex.^2);
        SNRx(i) = 10*log10(Px/Pex);
    end   










