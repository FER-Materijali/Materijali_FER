import sys
import os
import re

def parse_filename(filename):
    m = re.match(r"Lab_(\d+)_g(\d+).txt", filename)
    return int(m.group(1)), int(m.group(2))

students = {}

lines = [line.rstrip('\n') for line in open(sys.argv[1])]
for line in lines:
    jmbag, name = line.split(' ', 1)
    students[jmbag] = name

results = {}
labs = []
for file in os.listdir("."):
    if file.startswith('Lab'):
        lab, group = parse_filename(file)

        if not lab in labs:
            labs.append(lab)

        lines = [line.rstrip('\n') for line in open(file)]
        for line in lines:
            jmbag, result = line.split(' ')

            if (jmbag, lab) in results:
                print("Duplicate {0}, {1}".format(jmbag, lab))
            else:
                results[(jmbag, lab)] = result

header = "%-15s %-20s" % ("JMBAG", "Prezime, ime")
for lab in sorted(labs):
    header += "L%-4s" % (lab)
print(header)

for student in students.keys():
    line = "%-15s %-20s" % (student, students[student])
    for lab in sorted(labs):
        if (student, lab) in results:
            line += "%-5s" % ( results[(student, lab)] )
        else:
            line += "%-5s" % ( "-" )

    print(line)
