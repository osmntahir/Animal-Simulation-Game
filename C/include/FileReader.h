#ifndef FILEREADER_H
#define FILEREADER_H

#include "Habitat.h"

typedef struct FILE_READER {
    int row;
    int column;
    Habitat habitat;
    void (*readFile)(struct FILE_READER *);
    void (*deleteFileReader)(struct FILE_READER *);
    
} *FileReader;

FileReader newFileReader();
void readFile(const FileReader);
void deleteFileReader(const FileReader);
Living createNewLiving(int);


#endif /* FILEREADER_H */
