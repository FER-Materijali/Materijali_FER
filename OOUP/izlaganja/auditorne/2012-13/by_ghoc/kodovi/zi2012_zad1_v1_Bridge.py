

class Shape:
    def draw(self):
        raise NotImplementedError

    def setTracer(self, t):
        print(" - Objektu klase %s mijenjam implementaciju tracera: %s\
\n" % (self.__class__.__name__, t.__class__.__name__))
        self.tracerImpl = t


class ShapeText(Shape):
    def draw(self):
        self.tracerImpl.drawText(self)


class ShapeLine(Shape):
    def draw(self):
        self.tracerImpl.drawLine(self)

class ShapeTriangle(Shape):
    def draw(self):
        self.tracerImpl.drawTriangle(self)



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
        

def iscrtaj(shapes):
    for shape in shapes:
        shape.draw()
    print("\n")

def test():
    
    
    trokut1 = ShapeTriangle()
    trokut1.setTracer(TracerWin32())

    trokut2 = ShapeTriangle()
    trokut2.setTracer(TracerWin32())

    textOzn1 = ShapeText()
    textOzn1.setTracer(TracerWin32())

    line1 = ShapeLine()
    line1.setTracer(TracerWin32())

    shapes = [trokut1, trokut2, textOzn1, line1]
    iscrtaj(shapes)
    
    trokut2.setTracer(TracerSVG())
    line1.setTracer(TracerSVG())

    iscrtaj(shapes)

test()
