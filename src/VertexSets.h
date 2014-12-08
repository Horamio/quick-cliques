#ifndef VERTEX_SETS_H
#define VERTEX_SETS_H

#include <vector>
#include <list>
#include <vector>
#include <string>

class VertexSets {
public:
    VertexSets(std::string const &name) : m_bDoneWithTopLevelPartitions(false), m_sName(name) {}
    virtual ~VertexSets() {}

    VertexSets           (VertexSets const &sets) = delete;
    VertexSets& operator=(VertexSets const &sets) = delete;

    virtual void MoveFromPToR(int const vertexInP) __attribute__((always_inline)) = 0;
    virtual void MoveFromRToX(int const vertexInP) __attribute__((always_inline)) = 0;

    virtual void ReturnVerticesToP(std::vector<int> const &vVertices) __attribute__((always_inline)) = 0;

    virtual std::vector<int> ChoosePivot() const __attribute__((always_inline)) = 0;
    virtual bool InP(int const vertex) const __attribute__((always_inline)) = 0;

    virtual bool PIsEmpty() const __attribute__((always_inline)) = 0;
    virtual bool XAndPAreEmpty() const __attribute__((always_inline)) = 0;

    virtual size_t SizeOfX() const = 0;
    virtual size_t SizeOfP() const = 0;

    virtual size_t RemainingSizeEstimate() const { return SizeOfP(); }

    virtual void Initialize() = 0;

    virtual void PrintSummary(int const /*lineNumber*/) const {}

    virtual bool GetNextTopLevelPartition() = 0;

    virtual void GetTopLevelPartialClique(std::list<int> &/*partialClique*/) const = 0;

    virtual void RemoveDominatedVertices(std::vector<int> &dominatedVertices) {}

    virtual void ReturnDominatedVertices(std::vector<int> const &dominatedVertices) {}

    std::string GetName() { return m_sName; }

    virtual size_t GetGraphSize() const = 0;

protected:
    class SetDelineator {
    public:
        SetDelineator(int const beginX, int const beginP, int const beginR) : m_BeginX(beginX), m_BeginP(beginP), m_BeginR(beginR) {}
        int m_BeginX;
        int m_BeginP;
        int m_BeginR;
    };

    bool m_bDoneWithTopLevelPartitions;

private:
    std::string m_sName;
};

#endif //VERTEX_SETS_H
