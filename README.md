Given a list of amino acid sequences (where each amino acid is represented by a single letter,) the program compares the differences in sequences and gives you a table showing how different each sequence is to each other.

I wrote this for some AP Biology homework that we had on phylogenetics.

### Example

// startup

0. IKIIIIGSGV GGTAAAARLS KKGFQVEVYE KNSYNGGRCS IIR_HNGHRF DQHPSL__YL
1. KRTFVIGAGF GGLALAIRLQ AAGIATTVLE QHDKPGGRAY VWQ_DQGFTF DAGPTV__IT
2. MKIAVIGAGV TGLAAAARIA SQGHEVTIFE KNNNVGGRMN QLK_KDGFTF DMGPTI__VM
3. KKVVIIGAGA GGTALAARLG RRGYSVTVLE KNSFGGGRCS LIH_HDGHRW DQGPSL__YL
4. KSVIVIGAGV GGVSTAARLA KAGFKVTILE KNDFTGGRCS LIH_NDGHRF DQGPSL__LL
5. WDAVVIGGGH NGLTAAAYLA RGGLSVAVLE RRHVIGGAAV TEEIVPGFKF SRCSYLQGLL
6. compute
  0   1   2   3   4   5   
0     38   33   20   23   42   
1 38       33   33   32   42   
2 33   33       33   30   42   
3 20   33   33       18   40   
4 23   32   30   18       40   
5 42   42   42   40   40

// exit with exitcode 0
