/*
 *
 * compile: "g++ -std=gnu++11 -o NewEvaluatorPPJ NewEvaluatorPPJ.cpp"
 *
 * Testirano na:   Windows 10    64bit
 *                 Lubuntu 16.10 64bit
 * 
 * Nije perfektno, ali radi prema uputama.
 *
 */

#include <stdio.h>

#define STRING_MAX_LENGTH (int)1e6 +1

#ifdef _WIN32
#define PATH_SEPARATOR "\\"
#else
#define PATH_SEPARATOR "/"
#endif


int main(int argc, char **argv) {

    char *languageRuntimeFileName    = new char[501];
    char *evaluatingScriptName       = new char[501];
    char *testingUnitsRootFolderName = new char[501];
    char *testingUnitsSubfolderName  = new char[501];
    char *testingUnitInputFileName   = new char[501];
    char *testingUnitOutputFileName  = new char[501];
    int testUnitsRangeBegin;
    int testUnitsRangeEnd;

    printf("\nWork for Java and Python solutions.\n\n");
    printf("Make sure that you are located in the same folder as are testing root folder and your code script.\n");
    printf("i.e.   - current console location directory\n");
    printf("            - testing root folder\n");
    printf("               - test unit subfolder containing input and output files\n");
    printf("            - your code script\n");



    char answer = 'n';
    FILE *logStream;

    logStream = fopen("NewEvaluatorPPJLastTesting.log", "r");

    if( logStream != NULL ) {
        fscanf(logStream, "%s", languageRuntimeFileName);
        fscanf(logStream, "%s", evaluatingScriptName);
        fscanf(logStream, "%s", testingUnitsRootFolderName);
        fscanf(logStream, "%s", testingUnitsSubfolderName);
        fscanf(logStream, "%s", testingUnitInputFileName);
        fscanf(logStream, "%s", testingUnitOutputFileName);
        fscanf(logStream, "%d", &testUnitsRangeBegin);
        fscanf(logStream, "%d", &testUnitsRangeEnd);

        fclose(logStream);
        
        do {
            printf("\n____________________________________________________\n");
            printf("These were your last testings.\n");
            printf("   - language runtime file    : %s\n", languageRuntimeFileName);
            printf("   - your evaluating script   : %s\n", evaluatingScriptName);
            printf("   - testing root folder name : %s\n", testingUnitsRootFolderName);
            printf("   - subfolder with test units: %s\n", testingUnitsSubfolderName);
            printf("   - testing unit input file  : %s\n", testingUnitInputFileName);
            printf("   - testing unit output file : %s\n", testingUnitOutputFileName);
            printf("   - range begin: %d\n", testUnitsRangeBegin);
            printf("   - range end  : %d\n", testUnitsRangeEnd);
            printf("\nDo you wish to use them? ( y / n)   ");
            scanf(" %c", &answer);
        } while( answer!='y' && answer!='n' );
    }


    if( answer == 'n' ) {
        printf("\nEnter name of your language runtime file (e.g. 'python3' or 'python' or 'java' ; make sure it is in envvar or in current console directory): ");
        scanf("%s", languageRuntimeFileName);

        FILE *checkFileStream;
        while(true) {
            printf("\nEnter name of a script to be evaluated (e.g. 'name.py' ; for java class file write full name, INCLUDE '.class' extension): ");
            scanf(" %[^\n]", evaluatingScriptName);

            checkFileStream = fopen(evaluatingScriptName, "r");
            if(checkFileStream == NULL) {
                printf("\nFile '%s' DOES NOT EXIST in current directory !\n\n", evaluatingScriptName);
            } else {
                fclose(checkFileStream);
                break;
            }
        }

        printf("\nEnter name of a root folder where testing subfolders are: ");
        scanf("%s", testingUnitsRootFolderName);

        printf("\nEnter name of a subfolder containing test unit (subfolders must be in format 'namexx' where 'xx' is number of test unit ; e.g. if subfolders are 'test00' and 'test01', enter just 'test' without numbers): ");
        scanf("%s", testingUnitsSubfolderName);

        printf("\nEnter name of testing unit input file (e.g. 'test.in'): ");
        scanf("%s", testingUnitInputFileName);

        printf("\nEnter name of testing unit output file (e.g. 'test.out'): ");
        scanf("%s", testingUnitOutputFileName);

        printf("\nEnter range of test units (e.g. 'from: 0' and 'to: 20').\n");
        do {
            printf("\tfrom: ");
            scanf("%d", &testUnitsRangeBegin);
        } while( testUnitsRangeBegin < 0 );
        do {
            printf("\tto  : ");
            scanf("%d", &testUnitsRangeEnd);
        } while( testUnitsRangeEnd < testUnitsRangeBegin );
    }



    logStream = fopen("NewEvaluatorPPJLastTesting.log", "w");

    fprintf(logStream, "%s\n", languageRuntimeFileName);
    fprintf(logStream, "%s\n", evaluatingScriptName);
    fprintf(logStream, "%s\n", testingUnitsRootFolderName);
    fprintf(logStream, "%s\n", testingUnitsSubfolderName);
    fprintf(logStream, "%s\n", testingUnitInputFileName);
    fprintf(logStream, "%s\n", testingUnitOutputFileName);
    fprintf(logStream, "%d\n", testUnitsRangeBegin);
    fprintf(logStream, "%d\n", testUnitsRangeEnd);

    fclose(logStream);



    // prepare Java byte code file, remove '.class' extension
    int scriptNameLength = 0;
    while( evaluatingScriptName[scriptNameLength] != '\0' ) {
        ++scriptNameLength;
    }

    if( scriptNameLength > 6 ) {
        if( evaluatingScriptName[scriptNameLength-1]=='s' &&
            evaluatingScriptName[scriptNameLength-2]=='s' &&
            evaluatingScriptName[scriptNameLength-3]=='a' &&
            evaluatingScriptName[scriptNameLength-4]=='l' &&
            evaluatingScriptName[scriptNameLength-5]=='c' &&
            evaluatingScriptName[scriptNameLength-6]=='.') {
                evaluatingScriptName[scriptNameLength-6] = '\0';
        }
    }



    int *resultTable = new int[testUnitsRangeEnd-testUnitsRangeBegin +1];
    // 0 - incorrect output
    // 1 - correct output
    // 2 - input file does not exist
    // 3 - output file does not exist
    // 4 - both input and output file do not exist

    int resultTableCounter = 0;
    char *commandBuffer = new char[501];
    FILE *resultStream;
    char *resultBuffer = new char[STRING_MAX_LENGTH];
    FILE *readFileStream;
    char *readFileBuffer = new char[STRING_MAX_LENGTH];


    for(int i=testUnitsRangeBegin; i<=testUnitsRangeEnd; ++i, ++resultTableCounter) {
        bool flagErrorOccurred = false;

        printf("\n\n____________________________________________\n");
        printf("\nEvaluating test unit #%02d\n", i);

        sprintf(commandBuffer, "%s%s%s%02d%s%s", testingUnitsRootFolderName,
                                                 PATH_SEPARATOR,
                                                 testingUnitsSubfolderName,
                                                 i,
                                                 PATH_SEPARATOR,
                                                 testingUnitInputFileName);
        resultStream = fopen(commandBuffer, "r");
        if(resultStream == NULL) {
            flagErrorOccurred = true;

            resultTable[resultTableCounter] = 2;
            resultBuffer = NULL;
            printf("\n\nYour result  ERROR  File does not exist !\n");
        } else {
            fclose(resultStream);

            sprintf(commandBuffer, "%s %s < %s%s%s%02d%s%s", languageRuntimeFileName,
                                                             evaluatingScriptName,
                                                             testingUnitsRootFolderName,
                                                             PATH_SEPARATOR,
                                                             testingUnitsSubfolderName,
                                                             i,
                                                             PATH_SEPARATOR,
                                                             testingUnitInputFileName);
        
            resultStream = popen(commandBuffer, "r");
            fscanf(resultStream, "%[^\r]", resultBuffer);
            pclose(resultStream);

            printf("\n\nYour result\n%s", resultBuffer);
        }

        sprintf(commandBuffer, "%s%s%s%02d%s%s", testingUnitsRootFolderName,
                                                 PATH_SEPARATOR,
                                                 testingUnitsSubfolderName,
                                                 i,
                                                 PATH_SEPARATOR,
                                                 testingUnitOutputFileName);

        readFileStream = fopen(commandBuffer, "r");
        if(readFileStream == NULL) {
            resultTable[resultTableCounter] = (flagErrorOccurred) ? 4 : 3 ;
            readFileBuffer = NULL;
            printf("\n\nCorrect result  ERROR  File does not exist !\n\n\n");
            continue;
        }
        fscanf(readFileStream, "%[^\r]", readFileBuffer);
        fclose(readFileStream);

        printf("\n\nCorrect result\n%s\n\n", readFileBuffer);

        if(flagErrorOccurred) {
            continue;
        }

        for(int e=0; ; ++e) {
            if(resultBuffer[e] != readFileBuffer[e]) {
                resultTable[resultTableCounter] = 0;
                break;
            } else if(resultBuffer[e] == '\0') {
                resultTable[resultTableCounter] = 1;
                break;
            }
        }
    }



    delete[] readFileBuffer;
    delete[] resultBuffer;
    delete[] commandBuffer;

    delete[] testingUnitOutputFileName;
    delete[] testingUnitInputFileName;
    delete[] testingUnitsSubfolderName;
    delete[] testingUnitsRootFolderName;
    delete[] evaluatingScriptName;
    delete[] languageRuntimeFileName;


    resultTableCounter = 0;
    int correctCounter = 0;
    for(int i=testUnitsRangeBegin; i<=testUnitsRangeEnd; ++i, ++resultTableCounter) {
        printf("Testing unit #%02d :   ", i);

        switch( resultTable[resultTableCounter] ) {
            case 0: printf("INcorrect result\n");
                    break;
            case 1: printf("CORRECT result\n");
                    break;
            case 2: printf("Testing input FILE DOES NOT EXIST !\n");
                    break;
            case 3: printf("Testing output FILE DOES NOT EXIST !\n");
                    break;
            case 4: printf("Testing FILES DO NOT EXIST !\n");
                    break;
        }

        if(resultTable[resultTableCounter] == 1) {
            ++correctCounter;
        }
    }

    printf("\nYou have %d successful testings out of %d !\n", correctCounter, testUnitsRangeEnd-testUnitsRangeBegin +1);


    delete[] resultTable;


    return 0;
}