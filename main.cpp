#include <iostream>
#include <vector>

// length_cap in this use case is guarenteed to be smaller than the lengths of seq1 and seq1
unsigned long compare_sequences(std::size_t length_cap, std::string seq1, std::string seq2)
{
    unsigned long differences = 0;

    for (std::size_t i = 0; i < length_cap; ++i)
    {
        if (seq1[i] != seq2[i])
        {
            ++differences;
        }
    }
    return differences;
}

int main()
{
    // You input several amino acid sequences, all of the same length, and the program compares them and tells you
    // how they're all different
    std::vector<std::string> sequences;
    std::string input;
    std::size_t smallest = 0xffffffffffffffff;

    // IKIIIIGSGV GGTAAAARLS KKGFQVEVYE KNSYNGGRCS IIR_HNGHRF DQHPSL__YL Acyrthosiphon (aphid)
    // KRTFVIGAGF GGLALAIRLQ AAGIATTVLE QHDKPGGRAY VWQ_DQGFTF DAGPTV__IT Pantoea (bacterium)
    // MKIAVIGAGV TGLAAAARIA SQGHEVTIFE KNNNVGGRMN QLK_KDGFTF DMGPTI__VM Staphylococcus (bacterium)
    // KKVVIIGAGA GGTALAARLG RRGYSVTVLE KNSFGGGRCS LIH_HDGHRW DQGPSL__YL Ustilago (fungus)
    // KSVIVIGAGV GGVSTAARLA KAGFKVTILE KNDFTGGRCS LIH_NDGHRF DQGPSL__LL Gibberella (fungus)
    // WDAVVIGGGH NGLTAAAYLA RGGLSVAVLE RRHVIGGAAV TEEIVPGFKF SRCSYLQGLL Arabidopsis (plant)

    // AN AMINO ACID IS REPRESENTED BY A SINGLE CHAR

    unsigned long counter = 0;

    do
    {
        std::cout << counter++ << ". " << std::flush;
        std::getline(std::cin, input);

        if (input == "stop")
        {
            break; // exit the loop for post processing
        } else if (input == "compute")
        {
            std::size_t size = sequences.size();
            // compute the differences between each amino acid sequence
            unsigned long table[size][size];

            for (std::size_t i = 0; i < size; ++i)
            {
                for (std::size_t j = 0; j < size; ++j)
                {
                    table[i][j] = compare_sequences(smallest, sequences[j], sequences[i]);
                }
            }

            std::cout << "  ";
            for (std::size_t i = 0; i < size; ++i)
            {
                std::cout << i << "   ";
            }
            std::cout << std::endl;
            for (std::size_t i = 0; i < size; ++i)
            {
                std::cout << i << ' ';
                for (std::size_t j = 0; j < size; ++j)
                {
                    if (i == j)
                    {
                        std::cout << "    ";
                    } else
                    {
                        std::cout << table[i][j] << "   ";
                    }
                }
                std::cout << std::endl;
            }



            break; // exit the loop for post processing
        }

        sequences.push_back(input);

        // as we go along keep track of the smallest sequence, because that's how many chars we'll compare in each.
        // Any overflow will be ignored (for now)
        if (input.size() < smallest)
        {
            smallest = input.size();
        }
    } while (input != "stop");

    return 0;
}
