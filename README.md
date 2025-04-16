# ANS

git clone https://github.com/pawello85/ANS

D-R - dioda z równoległym rezystorem (obliczyć moc na diodzie)

Dane: E, R, R_0, U_D0, r_D


W = OFF

Ix = (E - U_D0) / (R + r_D)
Ux = Ix * r_D + U_D0
Rx = (R * r_D) / (R + r_D)


W = ON

U_D = (Ux *R_0) / (Rx + R_0)
I_D = (U_D - U_D0) / r_D
P_D = U_D * I_D

(jeśli wyliczyć delta U_D) to dU_D% = (Ux - U_D) / U_D0