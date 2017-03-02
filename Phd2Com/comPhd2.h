/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   comPhd2.h
 * Author: eleve
 *
 * Created on 1 mars 2017, 16:51
 */

#ifndef COMPHD2_H
#define COMPHD2_H

class comPhd2 {
public:
    comPhd2();
    comPhd2(const comPhd2& orig);
    virtual ~comPhd2();
    void lancerAutoguidage (float pixel, int temps); //{"method": "guide", "params": [{"pixels": 1.5, "time": 8, "timeout": 40}, false], "id": 42}
    void modifierTempsExposition(int temps);//{"method": "set_exposure", "params": [1500], "id": 2}
    void modifierConnexionEquipement (); //{"method": "set_connected"}
    void trouverEtoile (); //{"method": "find_star"}
private:

};

#endif /* COMPHD2_H */

