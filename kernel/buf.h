struct buf {
  int valid;   // has data been read from disk?
  int disk;    // does disk "own" buf?
  uint dev;
  uint blockno;//磁盘块编号
  struct sleeplock lock;
  uint refcnt;//引用计数
  // struct buf *prev; // LRU cache list
  struct buf *next;
  uchar data[BSIZE];

  uint lastuse;//用于跟踪LRU-buf
};

