//
// Created by tothg on 09/05/22.
//

#ifndef SRC_SET_HPP
#define SRC_SET_HPP

///======================= Tároló osztály =======================///
/// Ez az osztály a 8. labor megoldásom, kisebb módosításokkal.
template<class T, int max = 10>
class Set{
    T *adat;    /// Adat tömb amit tárolunk
    int n;      /// tömb mérete
public:
    explicit Set(int n = 0) :n(n) {
        adat = new T[n];
    }
    int size(){return n;}
    bool isElement(T par) {
        Pr(Hello);
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
    ~Set(){delete [] adat;}
};

#endif //SRC_SET_HPP
