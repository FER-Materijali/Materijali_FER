class Object(object):
    def load():
        pass
    
class Object1(Object):
    @staticmethod
    def name():
        return '1'
    def load():
        return 1
    
class Object2(Object):
    @staticmethod
    def name():
        return '2'
    def load():
        return 2
    
class Object3(Object):
    @staticmethod
    def name():
        return '3'
    def load():
        return 3
    
def ObjectFactory(baseClass, name):
    for cls in baseClass.__subclasses__():
        if cls.name() == name:
            return cls()
    raise ValueError
    
def LoadDrawing(inputStream):
    for line in inputStream.split('\n'):
        yield ObjectFactory(Object, line[0])
        
input = "\n".join(['1', '2', '3', '2', '1', '3'])
for o in LoadDrawing(input):
    print type(o).__name__