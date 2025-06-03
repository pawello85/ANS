import math

Beta = float(input("Beta = "))
print("Beta =", Beta)

I_b = float(input("I_b = "))
print("I_b =", I_b,"[mA]")

I_cx = Beta * I_b
print(f"---\n{I_cx}[mA]\n---")

U_cc = float(input("U_cc = "))
print("U_cc =", U_cc,"[V]")

R_c = float(input("R_c = "))
print("R_c =", R_c,"[Ohm]")

U_ce = U_cc - R_c * I_cx / 1000
print("---\nU_ce = U_cc - R_c * I_cx =",U_ce, "[V]\n---")

print("2)")
gm =float(input("gm ="))
r_ce = float(input("r_ce ="))
A = float(input("A ="))
r_wy = R_c * r_ce /(R_c + r_ce)
k_uo = round(- gm * r_wy,0)
print(k_uo)
B = abs(k_uo * A)
print(B)
print("3)")