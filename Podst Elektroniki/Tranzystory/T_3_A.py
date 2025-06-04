# import math
# Dane
print("Dane:")

Beta = float(input("Beta = "))
I_b = float(input("I_b [mA] = "))
U_cc = float(input("U_cc [V] = "))
R_c = float(input("R_c [Ohm] = "))
gm = float(input("gm [S] = "))
r_ce = float(input("r_ce [Ohm] = "))
A = float(input("A [V] = "))
R_o = float(input("R_o [Ohm] = "))
R_g = float(input("R_g [Ohm] = "))


print("\n---\nWyniki:")

# 1)
I_cx = Beta * I_b
print("1)\nI_cx = Beta * I_b\nI_cx =",I_cx,"[mA]\n")

U_ce = U_cc - R_c * I_cx / 1000
print("U_ce = U_cc - R_c * I_cx \nU_ce =",U_ce, "[V]")


# 2) Amplituda dla biegu jaowego

print("\n2)")

r_wy = round(R_c * r_ce /(R_c + r_ce),2)

print("r_wy = R_c * r_ce /(R_c + r_ce)\nr_wy =", r_wy,"[Ohm]\n")
k_uo = round(-gm * r_wy,0)
print("k_uo = -gm * r_wy \nk_uo=", k_uo)

B = abs(k_uo * A)
print("B =", B, "V")


# 3) 

print("\n3)")



k_u = round(k_uo * R_o /(R_o + r_wy),0)
B = abs(k_u * A)
print("k_u = ", k_u)
print("B =", B, "V")


# 4)

print("\n4)")
R_BE = Beta/gm

k_uc = round(k_u * R_BE/ (R_BE + R_g),0)
B = abs(k_uc * A)

print("k_uc = ", k_uc)
print("B =", B, "V\n---")







