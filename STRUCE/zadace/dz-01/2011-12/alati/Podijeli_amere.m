function [ mUcenje, mProvjera ] = Podijeli_amere( m )

mUcenje = m((m(:,8) == 1),:);
mProvjera = m((m(:,8) ~=1),:);

end

