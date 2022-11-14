

class Shape:
    def draw(self, tracer):
        raise NotImplementedError


class ShapeText(Shape):
    def draw(self, tracer):
        tracer.drawText(self)

class ShapeLine(Shape):
    def draw(self, tracer):
        tracer.drawLine(self)

class ShapeTriangle(Shape):
    def draw(self, tracer):
        tracer.drawTriangle(self)



class Tracer:
    def drawText(self, shapeText):
        raise NotImplementedError

    def drawLine(self, shapeLine):
        raise NotImplementedError

    def drawTriangle(self, shapeTriangle):
        raise NotImplementedError


class TracerWin32(Tracer):
    def drawText(self, shapeText):
        print("Iscrtavanje tekstualnih oznaka na Win32 sustavu")
        print(" - id tekstualnih oznaka: %d" %id(shapeText))

    def drawLine(self, shapeLine):
        print("Iscrtavane linije na Win32 sustavu")
        print(" - id linije: %d" %id(shapeLine))
        
    def drawTriangle(self, shapeTriangle):
        print("Iscrtavanje trokuta na Win32 sustavu")
        print(" - id trokuta: %d" %id(shapeTriangle))
        

class TracerXWin(Tracer):
    def drawText(self, shapeText):
        print("Iscrtavanje tekstualnih oznaka na XWin sustavu")
        print(" - id tekstualnih oznaka: %d" %id(shapeText))
        
    def drawLine(self, shapeLine):
        print("Iscrtavane linije na XWin sustavu")
        print(" - id linije: %d" %id(shapeLine))
        
    def drawTriangle(self, shapeTriangle):
        print("Iscrtavanje trokuta na XWin sustavu")
        print(" - id trokuta: %d" %id(shapeTriangle))
        

class TracerSVG(Tracer):
    def drawText(self, shapeText):
        print("Iscrtavanje tekstualnih oznaka u datotecni format SVG")
        print(" - id tekstualnih oznaka: %d" %id(shapeText))
        
    def drawLine(self, shapeLine):
        print("Iscrtavane linije u datotecni format SVG")
        print(" - id linije: %d" %id(shapeLine))
        
    def drawTriangle(self, shapeTriangle):
        print("Iscrtavanje trokuta u datotecni format SVG")
        print(" - id trokuta: %d" %id(shapeTriangle))
        

def iscrtaj(shapes, tracer):
    for shape in shapes:
        shape.draw(tracer)
    print("\n")


def test():

    trokut1 = ShapeTriangle()
    trokut2 = ShapeTriangle()
    textOzn1 = ShapeText()
    line1 = ShapeLine()

    shapes = [trokut1, trokut2, textOzn1, line1]

    tracerImpWin32 = TracerWin32()
    iscrtaj(shapes, tracerImpWin32)
    
    tracerXWin = TracerXWin()
    iscrtaj(shapes, tracerXWin)

test()
