/******************************************************************************
 * File Name    : guessbyte.h
 * Coder        : Aziz Gökhan NARİN
 * E-Mail       : azizgokhannarin@yahoo.com
 * Explanation  : Guessing Byte Pairs
 * Versiyon     : 1.0.0
 ******************************************************************************/

#ifndef GUESSBYTE_H
#define GUESSBYTE_H

#include <cinttypes>
#include <atomic>
#include <mutex>
#include <map>

class GuessByte
{
public:
    explicit GuessByte();
    virtual ~GuessByte();

    void encode(const uint8_t &firstValue, const uint8_t &secondValue, uint16_t &encodedPair);
    void decode(uint8_t &firstValue, uint8_t &secondValue, const uint16_t &encodedPair);

protected:
    void maskValue(const uint8_t &value, uint8_t &mask, uint8_t &R);
    void unmaskValue(uint8_t &value, const uint8_t &mask, const uint8_t &R);
    void findCoordinates(const uint8_t &value, uint8_t &X, uint8_t &Y, uint8_t &Z, uint8_t &R);
    void findValue(uint8_t &value, const uint8_t &X, const uint8_t &Y, const uint8_t &Z, const uint8_t &R);

private:
    void selectS(uint8_t &X2, const uint8_t &Z2, uint8_t &S);
    void guessZ2(const uint8_t &X1, const uint8_t &Z1, const uint8_t &C, const uint8_t &S);

    void matchEvenEvenOddOddLevel1(const uint8_t X1, const uint8_t Z1, const uint8_t &C, const uint8_t &conditions);
    void matchEvenEvenOddOddLevel2(const uint8_t X1, const uint8_t Z1, const uint8_t &C, const uint8_t &conditions);

    void matchOddEvenEvenOddLevel1(const uint8_t X1, const uint8_t Z1, const uint8_t &C, const uint8_t &conditions);
    void matchOddEvenEvenOddLevel2(const uint8_t X1, const uint8_t Z1, const uint8_t &C, const uint8_t &conditions);

    bool testEvenEvenOddOdd(const uint8_t X1, const uint8_t Z1, const uint8_t X2, const uint8_t Z2,
                            const uint8_t &conditions) const;
    bool testOddEvenEvenOdd(const uint8_t X1, const uint8_t Z1, const uint8_t X2, const uint8_t Z2,
                            const uint8_t &conditions) const;
    void setResult(const uint8_t X2, const uint8_t Y2, const uint8_t Z2);

    std::atomic<bool> solutionFound;
    std::atomic<bool> stopAll;
    std::mutex resultMutex;
    uint8_t finalResult;
    int totalCalculating = 0;
};

#endif // GUESSBYTE_H
