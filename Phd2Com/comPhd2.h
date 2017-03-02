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
    void connexionProgramme (); // Création socket, connection ...
    void lancerAutoguidage (float pixel, int temps, bool calibration); //{"method": "guide", "params": [{"pixels": 1.5, "time": 8, "timeout": 40}, false], "id": 42} calibration doit être 0 ou 1, 0 = false, 1 = true
    void modifierTempsExposition(int temps);//{"method": "set_exposure", "params": [1500], "id": 2}
    void connexionEquipement (); //{"method": "set_connected"}
    void trouverEtoile (); //{"method": "find_star"}
    void recevoirListeProfils (); // SEND get_profiles GET array of {"id":profile_id,"name":"profile_name"}
    void changerProfil (int id); // {"method": "set_profile", "params": [2]}  Ne pas oublier de deco l'équipement avant la requete
    void lancementPhd2 (); //Damien s'occupe de cette partie
    

private:

};

#endif /* COMPHD2_H */

