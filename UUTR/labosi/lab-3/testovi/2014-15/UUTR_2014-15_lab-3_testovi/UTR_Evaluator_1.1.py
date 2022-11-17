docs = """
Simple evaluator for UTR
Original by: http://www.fer2.net/showpost.php?p=2144786&postcount=68
Modified by: srolija

Version 1.1
- added flags for simpler runing of multiple tests
- removes temporrary files for correct test cases
- outputs error log and stops when runtime error encountered
- cleaned up code


How to run it?
--------------------------------------------------------------------------------

Defaults (python3, current directory contains testXX directories):
python test.py "program.exe"

Custom test directory (lab1_primjeri_2014)
python test.py "program.exe" --tests ./lab1_primjeri_2014

Custom file names (input.in & output.out):
python test.py "program.exe" --input test.in --output test.out

For python2 (download and install both)
C:\Python2\bin\python.exe test.py "C:\Python3\bin\python.exe program.py"

--------------------------------------------------------------------------------
"""

import argparse
import os
import subprocess
import sys
import tempfile
import time


parser = argparse.ArgumentParser(description=docs, formatter_class=argparse.RawTextHelpFormatter)
parser.add_argument("command", help="command for running program, add quotes for interpreters")
parser.add_argument("--input", help="file name of input file", default="primjer.in")
parser.add_argument("--output", help="file name of output file", default="primjer.out")
parser.add_argument("--tests", help="directory containing test directories", default=".")
parser.add_argument("--tmp", help="temporary file name", default = "t.u")

flags = parser.parse_args()


def get_tests() :
    tests = [] # Get all directories from current folder
    test_directory = os.path.relpath(flags.tests)

    for item in list(filter(os.path.isdir, [os.path.join(test_directory, d) for d in os.listdir(test_directory)])):

        # Check if they contain both input and output file
        if os.path.exists(os.path.join( item, flags.input)) and \
                os.path.exists(os.path.join( item, flags.output)):

            # If they do, add them to the list
            tests.append(item)

    return tests



def execute(tests) :

    if not tests :
        print("There are no tests to be run! Check your setup.")
        return

    execution, correct = 0, 0
    template_status = "[ {:6s} ] - {:.3f}ms | {}"

    print("\nTotal of {} tests will be run!".format(len(tests)), end="\n\n")

    ERROR_LOG = tempfile.TemporaryFile()

    for test in tests :

        # Generate paths for current test
        INPUT = os.path.join(test, flags.input)
        OUTPUT = os.path.join(test, flags.output)
        TMP = os.path.join(test, flags.tmp)

        # Construct command line
        cmd = flags.command + ' < ' + INPUT + " > " + TMP

        # Run program
        start = time.time()
        status = subprocess.call(cmd, shell=True, stdin=subprocess.PIPE, stdout=subprocess.DEVNULL, stderr=ERROR_LOG)
        end = time.time()

        # Stop and print upon error
        if status:
            print("Execution encountered error:")
            print("-" * 80)
            print(ERROR_LOG.text())
            return

        ok = False

        # Check if output is equal to expected
        with open (OUTPUT, 'U') as input_file:
            with open (TMP, 'U') as output_file:
                ok = input_file.read() == output_file.read()

        # Upon success remove output file
        if ok:
            os.remove(TMP)


        if ok : correct += 1
        print(template_status.format(test, end - start, ('pass' if ok else 'fail - x')))

    print('\nStats : {}/{} | {:.0f}%'.format(correct, len(tests), (correct / len(tests) * 100)))

# Let's run this motherfucker!!!
execute(get_tests())
