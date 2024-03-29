typedef struct RiffChunk RiffChunk;
typedef struct Riff Riff;

struct RiffChunk {
	char type[4];	// chunk type, i.e. 'LIST'
	ulong size;		// size of chunk in bytes
	char form[4];	// present if RIFF or LIST, otherwise 0
	vlong offset;	// offset of start of data file
};

struct Riff {
	RiffChunk header;
	char form[4];
};

int riffread(RiffChunk*, Biobuf*, void*, long);
void *riffsnarf(RiffChunk*, Biobuf*);
int rifftype(RiffChunk*, char*);
int riffchunk(RiffChunk*, Biobuf*);
