function [ mUcenje, mProvjera ] = Podijeli_primjere( m )

permutacije = randperm(size(m, 1));

mUcenje=m(permutacije(1:249),:);
mProvjera=m(permutacije(250:end),:);

end