//
// Created by tothg on 09/05/22.
//

#ifndef SRC_SET_HPP
#define SRC_SET_HPP

///======================= Tároló osztály =======================///
/// Ez az osztály a 8. labor megoldásom, kisebb módosításokkal.
template<class T, int max = 100>
class Set{
    T *adat;    /// Adat tömb amit tárolunk
    int n;      /// tömb mérete
public:
    explicit Set(int n = 0) :n(n) {
        adat = new T[n];
    }
    int size() const {return n;}
    bool isElement(T par) {
        for (int i =0; i < n; i++)
            if (adat[i] == par)
                return true;
        return false;
    }
    void insert(T par){
        if (isElement(par)){
            return;
        }
        if (n == max){
            throw "Túl sok elem";
        }
        T *temp = new T[n];
        for (int i = 0; i < n; i++){
            temp[i] = this->adat[i];
        }
        delete[] adat;
        adat = new T[n+1];
        for (int i = 0; i < n; i++){
            adat[i] = temp[i];
        }
        adat[n++] = par;
        delete [] temp;
    }
    T& operator[](int idx) const{
        if (idx < 0 || idx > n){
            throw std::out_of_range("Túlindexelés");}
        return adat[idx];
    }
    Set& operator=(const Set& rhs){
        delete[] this->adat;
        this->n = rhs.n;
        this->adat = new T[n];
        for (int i=0; i < n; i++){
            this->adat[i] = rhs[i];
        }
        return *this;
    }

    int lookup(int az) const{
        if (n == 0){
            return -1;
        }
        for (int i = 0; i < n; i++){
            if(adat[i].getId() == az)
                return i;
        }
        return -1;
    }

    ~Set(){delete [] adat;}
};

#endif //SRC_SET_HPP
