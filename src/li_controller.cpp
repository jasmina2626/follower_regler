#include "li_controller.h"


/*
Parameter in der Funktion:
lx =>  Ist X-Abstand in kartesischen Koordinaten
ly =>  Ist Y-Abstand in kartesischen Koordinaten
lxd => Soll X-Abstand in kartesischen Koordinaten
lyd => Soll Y-Abstand in kartesischen Koordinaten
ex => Differenzfehlermessung der X Koordinatenvon von Soll zu Ist Werten 
ey => Differenzfehlermessung der Y Koordinatenvon von Soll zu Ist Werten 
etheta => Differenzmessung der Orientierungswinkel von Leader zu Follower
*/

float vF(float k1, float k2, float XF, float XL, float YF, float YL, float phid, float ld, float thetaL, float thetaF, float d, float wL, float vL)
{
    float lx = -(XL - XF - d * cos(thetaF)) * cos(thetaL) - (YL - YF - d * sin(thetaF)) * sin(thetaL);
    float ly = (XL - XF - d * cos(thetaF)) * sin(thetaL) - (YL - YF - d * sin(thetaF)) * cos(thetaL);

    float lxd = ld * cos(phid);
    float lyd = ld * sin(phid);

    float ex = lxd - lx;
    float ey = lyd - ly;
    float etheta = thetaF - thetaL;

    float f1 = -wL * ld * sin(phid) + vL;
    float f2 = wL * ld * cos(phid);

    float v_F = (k1 * ex + wL * ey + f1) * cos(etheta) - (-k2 * ey + wL* ex - f2) * sin(etheta);

    return v_F;
}

float wF(float k1, float k2, float XF, float XL, float YF, float YL, float phid, float ld, float thetaL, float thetaF, float d, float wL, float vL)
{
    float lx = -(XL - XF - d * cos(thetaF)) * cos(thetaL) - (YL - YF - d * sin(thetaF)) * sin(thetaL);
    float ly = (XL - XF - d * cos(thetaF)) * sin(thetaL) - (YL - YF - d * sin(thetaF)) * cos(thetaL);

    float lxd = ld * cos(phid);
    float lyd = ld * sin(phid);

    float ex = lxd - lx;
    float ey = lyd - ly;
    float etheta = thetaF - thetaL;

    float f1 = -wL * ld * sin(phid) + vL;
    float f2 = wL * ld * cos(phid);

    float w_F = (1/d) * ((-k1 * ex - wL * ey - f1) * sin(etheta) - (-k2 * ey + wL * ex - f2) * cos(etheta));

    return w_F;
}