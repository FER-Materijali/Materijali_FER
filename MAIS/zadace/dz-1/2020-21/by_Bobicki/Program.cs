using System;
using System.Collections.Generic;
using System.IO;

namespace FirstHomework
{
    public class Program
    {
        private static double[,] K1Table = new double[8, 8] { {16, 11, 10, 16, 24, 40, 51, 61},
                       {12, 12, 14, 19, 26, 58, 60, 55},
                       {14, 13, 16, 24, 40, 57, 69, 56},
                       {14, 17, 22, 29, 51, 87, 80, 62},
                       {18, 22, 37, 56, 68, 109, 103, 77},
                       {24, 35, 55, 64, 81, 104, 113, 92},
                       {49, 64, 78, 87, 103, 121, 120, 101},
                       {72, 92, 95, 98, 112, 100, 103, 99}};

        private static double[,] K2Table = new double[8, 8] { {17, 18, 24, 47, 99, 99, 99, 99},
                       {18, 21, 26, 66, 99, 99, 99, 99},
                       {24, 26, 56, 99, 99, 99, 99, 99},
                       {47, 66, 99, 99, 99, 99, 99, 99},
                       {99, 99, 99, 99, 99, 99, 99, 99},
                       {99, 99, 99, 99, 99, 99, 99, 99},
                       {99, 99, 99, 99, 99, 99, 99, 99},
                       {99, 99, 99, 99, 99, 99, 99, 99}};


        public static void Main(string[] args)
        {
            try
            {
                var image = args[0];
                var blockNumber = int.Parse(args[1]);
                var outputFileName = args[2];
                if (blockNumber < 0 || blockNumber > 4095)
                {
                    Console.WriteLine("Please input valid block number (0-4095)!");
                    Environment.Exit(1);
                }
                PixelMap pixelMap = new PixelMap(image); // read ppm image
                var originalArray = pixelMap.ImageData;  //array of RGB values
                var pixelList = OrganizeToPixels(originalArray); // list of pixels with RGB values
                var pixelArray = pixelList.ToArray(); // array of pixels with RGB values
                var convertedArray = CalculateRGBToYCbCr(pixelArray); // array of YCbCr values
                var shiftedArray = ShiftForValue(convertedArray, -128); // array of YCbCr values shifted by -128
                var shiftedArray2D = ArrayTo2D(shiftedArray, 512); // 2D array of shifted YCbCr values
                var blocks = DivideArrayToBlocks(shiftedArray2D, 8); // list of blocks
                var calculatedDCT = CalculateDCT(blocks[blockNumber]); // object with 2D arrays of Y, Cb, Cr values after 2D-DCT
                var calculatedQuantization = CalculateQuantization(calculatedDCT); // object with 2D arrays of Y, Cb, Cr values after Quantization
                PrintOutputToTextFile(calculatedQuantization, outputFileName);
            }
            catch (Exception)
            {
                Console.WriteLine("Please input valid arguments ('image' 'block number' 'output .txt file')!");
                Environment.Exit(1);
            }
        }

        private static List<Pixel> OrganizeToPixels(byte[] array)
        {
            List<Pixel> pixelList = new List<Pixel>();
            for (var i = 0; i < array.Length; i += 3)
            {
                var R = array[i];
                var G = array[i + 1];
                var B = array[i + 2];
                var pixel = new Pixel(R, G, B);
                pixelList.Add(pixel);
            }
            return pixelList;
        }

        private static Pixel[] CalculateRGBToYCbCr(Pixel[] array)
        {
            Pixel[] convertedArray = new Pixel[array.Length];
            for (var i = 0; i < array.Length; i++)
            {
                var R = array[i].V1;
                var G = array[i].V2;
                var B = array[i].V3;
                var Y = 0.299 * R + 0.587 * G + 0.114 * B;
                var Cb = -0.1687 * R - 0.3313 * G + 0.5 * B + 128;
                var Cr = 0.5 * R - 0.4187 * G - 0.0813 * B + 128;
                convertedArray[i] = new Pixel(0, 0, 0);
                convertedArray[i].V1 = Y;
                convertedArray[i].V2 = Cb;
                convertedArray[i].V3 = Cr;
            }
            return convertedArray;
        }

        private static Pixel[] ShiftForValue(Pixel[] array, int value)
        {
            Pixel[] shiftedArray = new Pixel[array.Length];
            for (var i = 0; i < array.Length; i++)
            {
                shiftedArray[i] = new Pixel(0, 0, 0);
                shiftedArray[i].V1 = array[i].V1 + value;
                shiftedArray[i].V2 = array[i].V2 + value;
                shiftedArray[i].V3 = array[i].V3 + value;
            }
            return shiftedArray;
        }

        private static Pixel[,] ArrayTo2D(Pixel[] array, int value)
        {
            Pixel[,] array2D = new Pixel[value, value];
            var counter = 0;
            for (var i = 0; i < value; i++)
            {
                for (var j = 0; j < value; j++)
                {
                    array2D[i, j] = new Pixel(0, 0, 0);
                    array2D[i, j] = array[counter++];
                }
            }
            return array2D;
        }

        private static List<Pixel[,]> DivideArrayToBlocks(Pixel[,] array, int blockSize)
        {
            var arrayHeight = array.GetLength(0);
            var size = arrayHeight / blockSize * (arrayHeight / blockSize);
            List<Pixel[,]> blocks = new List<Pixel[,]>();
            for (var c = 0; c < size; c++)
            {
                Pixel[,] sub = new Pixel[blockSize, blockSize];
                var startX = (blockSize * (c / blockSize)) % arrayHeight;
                var startY = (blockSize * c) % arrayHeight;

                if (startY + blockSize > arrayHeight)
                {
                    startY = 0;
                }

                for (var row = 0; row < blockSize; row++)
                {
                    for (var column = 0; column < blockSize; column++)
                    {
                        sub[row, column] = array[startX + row, column + startY];
                    }
                }
                blocks.Add(sub);
            }
            return blocks;
        }

        private static CalculationDCT CalculateDCT(Pixel[,] array)
        {
            var arrayHeight = array.GetLength(0);
            var arrayWidth = array.GetLength(1);

            double[,] arrayY = new double[arrayHeight, arrayWidth];
            double[,] arrayCb = new double[arrayHeight, arrayWidth];
            double[,] arrayCr = new double[arrayHeight, arrayWidth];
            double cu;
            double cv;
            double dctY;
            double dctCb;
            double dctCr;
            double summY;
            double summCb;
            double summCr;

            for (var u = 0; u < arrayHeight; ++u)
            {
                for (var v = 0; v < arrayWidth; ++v)
                {
                    if (u == 0)
                    {
                        cu = 1.0 / Math.Sqrt(2.0);
                    }
                    else
                    {
                        cu = 1.0;
                    }
                    if (v == 0)
                    {
                        cv = 1.0 / Math.Sqrt(2.0);
                    }
                    else
                    {
                        cv = 1.0;
                    }
                    summY = 0;
                    summCb = 0;
                    summCr = 0;
                    for (var i = 0; i < arrayHeight; i++)
                    {
                        for (var j = 0; j < arrayWidth; j++)
                        {
                            dctY = array[i, j].V1 * Math.Cos((2 * i + 1) * u * Math.PI / 16.0) * Math.Cos((2 * j + 1) * v * Math.PI / 16.0);
                            dctCb = array[i, j].V2 * Math.Cos((2 * i + 1) * u * Math.PI / 16.0) * Math.Cos((2 * j + 1) * v * Math.PI / 16.0);
                            dctCr = array[i, j].V3 * Math.Cos((2 * i + 1) * u * Math.PI / 16.0) * Math.Cos((2 * j + 1) * v * Math.PI / 16.0);
                            summY += dctY;
                            summCb += dctCb;
                            summCr += dctCr;
                        }
                    }
                    arrayY[u, v] = 0.25 * cu * cv * summY;
                    arrayCb[u, v] = 0.25 * cu * cv * summCb;
                    arrayCr[u, v] = 0.25 * cu * cv * summCr;
                }
            }
            CalculationDCT calculatedDCT = new CalculationDCT(arrayY, arrayCb, arrayCr);
            return calculatedDCT;
        }

        private static CalculationQuantization CalculateQuantization(CalculationDCT calculationDCT)
        {
            var arrayHeight = calculationDCT.ArrayY.GetLength(0);
            var arrayWidth = calculationDCT.ArrayY.GetLength(1);

            int[,] arrayY = new int[arrayHeight, arrayWidth];
            int[,] arrayCb = new int[arrayHeight, arrayWidth];
            int[,] arrayCr = new int[arrayHeight, arrayWidth];

            for (var i = 0; i < arrayHeight; i++)
            {
                for (var j = 0; j < arrayWidth; j++)
                {
                    arrayY[i, j] = (int) Math.Round((calculationDCT.ArrayY[i, j] / K1Table[i, j]));
                    arrayCb[i, j] = (int) Math.Round((calculationDCT.ArrayCb[i, j] / K2Table[i, j]));
                    arrayCr[i, j] = (int) Math.Round((calculationDCT.ArrayCr[i, j] / K2Table[i, j]));
                }
            }
            CalculationQuantization calculatedQuantization = new CalculationQuantization(arrayY, arrayCb, arrayCr);
            return calculatedQuantization;
        }

        private static void PrintOutputToTextFile(CalculationQuantization calculatedQuantization, string outputFileName)
        {
            using (StreamWriter streamWriter = new StreamWriter(outputFileName))
            {
                Print2DArray(calculatedQuantization.ArrayY, streamWriter);
                streamWriter.WriteLine();
                Print2DArray(calculatedQuantization.ArrayCb, streamWriter);
                streamWriter.WriteLine();
                Print2DArray(calculatedQuantization.ArrayCr, streamWriter);
            }
        }

        public static void Print2DArray<T>(T[,] array, StreamWriter streamWriter)
        {
            var arrayHeight = array.GetLength(0);
            var arrayWidth = array.GetLength(1);

            for (int i = 0; i < arrayHeight; i++)
            {
                for (int j = 0; j < arrayWidth; j++)
                {
                    streamWriter.Write(array[i, j] + " ");
                }
                streamWriter.WriteLine();
            }
        }


        // Class which holds arrays of Y, Cb, Cr values after calculated 2D-DCT.
        class CalculationDCT
        {
            public double[,] ArrayY { get; set; }
            public double[,] ArrayCb { get; set; }
            public double[,] ArrayCr { get; set; }

            public CalculationDCT(double[,] arrayY, double[,] arrayCb, double[,] arrayCr)
            {
                this.ArrayY = arrayY;
                this.ArrayCb = arrayCb;
                this.ArrayCr = arrayCr;
            }
        }

        // Class which holds arrays of Y, Cb, Cr values after calculated quantization.
        class CalculationQuantization
        {
            public int[,] ArrayY { get; set; }
            public int[,] ArrayCb { get; set; }
            public int[,] ArrayCr { get; set; }

            public CalculationQuantization(int[,] arrayY, int[,] arrayCb, int[,] arrayCr)
            {
                this.ArrayY = arrayY;
                this.ArrayCb = arrayCb;
                this.ArrayCr = arrayCr;
            }
        }

        // Class which represents a pixel with it's RGB (or YCbCr) value.
        class Pixel
        {
            public double V1 { get; set; } // 1st value (R or Y)
            public double V2 { get; set; } // 2nd value (G or Cb)
            public double V3 { get; set; } // 3rd value (B or Cr)

            public Pixel(double v1, double v2, double v3)
            {
                this.V1 = v1;
                this.V2 = v2;
                this.V3 = v3;
            }
        }

        // Class which represents a block of pixels.
        class PixelBlock
        {
            public Pixel[,] Block { get; set; }

            public PixelBlock(Pixel[,] block)
            {
                this.Block = block;
            }
        }

        // Class which is used for reading ppm image.
        // It is an adjusted Pixelmap.cs class that is used by the PixelMapViewer application.
        class PixelMap
        {
            /// Struct which contains the objects that are found in the header of .pbm, .pgm, and .ppm files.
            [Serializable]
            public struct PixelMapHeader
            {
                private string magicNumber;
                /// "Magic Number" which identifies the type of Pixelmap. P1 = PBM (ASCII); P2 = PGM (ASCII); P3 = PPM (ASCII); P4 is not used; P5 = PGM (Binary); P6 = PPM (Binary).
                public string MagicNumber
                {
                    get { return magicNumber; }
                    set { magicNumber = value; }
                }

                private int width;
                public int Width
                {
                    get { return width; }
                    set { width = value; }
                }

                private int height;
                public int Height
                {
                    get { return height; }
                    set { height = value; }
                }

                private int depth;
                public int Depth
                {
                    get { return depth; }
                    set { depth = value; }
                }
            }

            private PixelMapHeader header;
            public PixelMapHeader Header
            {
                get { return header; }
                set { header = value; }
            }

            public byte[] ImageData { get; set; }

            public int BytesPerPixel { get; private set; }

            public PixelMap(string filename)
            {
                if (File.Exists(filename))
                {
                    FileStream stream = new FileStream(filename, FileMode.Open);
                    this.FromStream(stream);
                    stream.Close();
                }
                else
                {
                    throw new FileNotFoundException("The file " + filename + " does not exist", filename);
                }
            }

            private void FromStream(Stream stream)
            {
                int index;
                this.header = new PixelMapHeader();
                int headerItemCount = 0;
                BinaryReader binReader = new BinaryReader(stream);
                try
                {
                    while (headerItemCount < 4)
                    {
                        char nextChar = (char)binReader.PeekChar();
                        if (nextChar == '#')
                        {
                            while (binReader.ReadChar() != '\n') ;
                        }
                        else if (Char.IsWhiteSpace(nextChar))
                        {
                            binReader.ReadChar();
                        }
                        else
                        {
                            switch (headerItemCount)
                            {
                                case 0: // next item is Magic Number
                                    char[] chars = binReader.ReadChars(2);
                                    this.header.MagicNumber = chars[0].ToString() + chars[1].ToString();
                                    headerItemCount++;
                                    break;
                                case 1: // next item is the width.
                                    this.header.Width = ReadValue(binReader);
                                    headerItemCount++;
                                    break;
                                case 2: // next item is the height.
                                    this.header.Height = ReadValue(binReader);
                                    headerItemCount++;
                                    break;
                                case 3: // next item is the depth.
                                    if (this.header.MagicNumber == "P1" | this.header.MagicNumber == "P4")
                                    {
                                        headerItemCount++;
                                    }
                                    else
                                    {
                                        this.header.Depth = ReadValue(binReader);
                                        headerItemCount++;
                                    }
                                    break;
                                default:
                                    throw new Exception("Error parsing the file header.");
                            }
                        }
                    }

                    switch (this.header.MagicNumber)
                    {
                        case "P1": // 1 byte per pixel
                            this.BytesPerPixel = 1;
                            break;
                        case "P2": // 1 byte per pixel
                            this.BytesPerPixel = 1;
                            break;
                        case "P3": // 3 bytes per pixel
                            this.BytesPerPixel = 3;
                            break;
                        case "P4":
                            throw new Exception("Binary .pbm (Magic Number P4) is not supported at this time.");
                        case "P5":  // 1 byte per pixel
                            this.BytesPerPixel = 1;
                            break;
                        case "P6":  // 3 bytes per pixel
                            this.BytesPerPixel = 3;
                            break;
                        default:
                            throw new Exception("Unknown Magic Number: " + this.header.MagicNumber);
                    }
                    this.ImageData = new byte[this.header.Width * this.header.Height * this.BytesPerPixel];
                    if (this.header.MagicNumber == "P1" | this.header.MagicNumber == "P2" | this.header.MagicNumber == "P3") // ASCII Encoding
                    {
                        int charsLeft = (int)(binReader.BaseStream.Length - binReader.BaseStream.Position);
                        char[] charData = binReader.ReadChars(charsLeft);
                        string valueString = string.Empty;
                        index = 0;
                        for (int i = 0; i < charData.Length; i++)
                        {
                            if (Char.IsWhiteSpace(charData[i]))
                            {
                                if (valueString != string.Empty)
                                {
                                    this.ImageData[index] = (byte)int.Parse(valueString);
                                    valueString = string.Empty;
                                    index++;
                                }
                            }
                            else
                            {
                                valueString += charData[i];
                            }
                        }
                    }
                    else
                    {
                        int bytesLeft = (int)(binReader.BaseStream.Length - binReader.BaseStream.Position);
                        this.ImageData = binReader.ReadBytes(bytesLeft);
                    }
                }

                catch (EndOfStreamException e)
                {
                    Console.WriteLine(e.Message);
                    throw new Exception("Error reading the stream! ", e);
                }
                catch (Exception ex)
                {
                    Console.WriteLine(ex.Message);
                    throw new Exception("Error reading the stream! ", ex);
                }
                finally
                {
                    binReader.Close();
                }
            }

            private int ReadValue(BinaryReader binReader)
            {
                string value = string.Empty;
                while (!Char.IsWhiteSpace((char)binReader.PeekChar()))
                {
                    value += binReader.ReadChar().ToString();
                }
                binReader.ReadByte();
                return int.Parse(value);
            }
        }
    }
}