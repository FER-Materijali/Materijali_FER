class Skok:
  def __init__(self, linija):
    dijelovi = [dio.split(',') for dio in linija.strip().split('->')]
    self.iz, self.za         = tuple(dijelovi[0])
    self.u,  self.s, self.pa = tuple(dijelovi[1])

  def odgovara(self, stanje, znak):
    return self.iz == stanje and self.za == znak

class Stroj:
  def __init__(self, linije):
    self.prazan  = linije[2]
    self.stanje  = linije[3]
    self.ciljna  = linije[4].split(',')
    self.skokovi = [Skok(l) for l in linije[5:]]
    self.traka   = []
    self.mjesto  = 0

  def postavi(self, traka):
    self.traka = list(traka) + [self.prazan]

  def pokreni(self):
    koraci = 0

    while True:
      znak = self.traka[self.mjesto]
      skokovi = filter(lambda s: s.odgovara(self.stanje, znak), self.skokovi)
      if len(skokovi) < 1: break

      skok = skokovi[0]
      self.stanje = skok.u
      self.traka[self.mjesto] = skok.s
      koraci += 1

      if skok.pa == 'R':
        self.mjesto = self.mjesto + 1
        self.traka  = self.traka  + [self.prazan]
      else:
        self.mjesto = self.mjesto - 1

    return (koraci, 1 if self.stanje in self.ciljna else 0)

def utrlab3(definicijaTS, sadrzajTrake):
  stroj = Stroj(definicijaTS.strip('%').split('%'))
  stroj.postavi(sadrzajTrake)
  rezultat = stroj.pokreni()
  return "%d%%%d" % rezultat
