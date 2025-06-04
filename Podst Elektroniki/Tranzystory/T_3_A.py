# import math
# Dane
print("Dane:")
Beta = float(input("Beta = "))
gm = float(input("gm [S] = "))

I_b = float(input("I_b [mA] = "))
U_cc = float(input("U_cc [V] = "))
U_BE = float(input("U_BE [V] = "))
A = float(input("A [V] = "))

R_C = float(input("R_C [Ohm] = "))
R_B = float(input("R_B [Ohm] = "))
# R_C = float(input("R_C [Ohm] = "))

R_o = float(input("R_o [Ohm] = "))
R_g = float(input("R_g [Ohm] = "))

r_CE = float(input("r_ce [Ohm] = "))

print("\n---\nWyniki:")


# 1)
I_CX = Beta * I_b
print("1)\nI_cx = Beta * I_b\nI_CX =",I_CX,"[mA]\n")

U_ce = U_cc - R_C * I_CX / 1000
print("U_ce = U_cc - R_C * I_CX \nU_ce =",U_ce, "[V]")


# 2) Amplituda dla biegu jaowego

print("\n2)")

r_wy = round(R_C * r_CE /(R_C + r_CE),2)

print("r_wy = R_c * r_CE /(R_c + r_CE)\nr_wy =", r_wy,"[Ohm]\n")
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

k_uc = round(k_u * R_BE / (R_BE + R_g),0)
B = abs(k_uc * A)

print("k_uc = ", k_uc)
print("B =", B, "V\n---")

# Część B
# 1)

I_BX = (U_cc - U_BE) / R_B
I_CX = Beta * I_BX 
U_CEX = U_cc - (I_CX * R_C)

print("Część B")
print("1)\nI_CX = Beta * I_b\nI_CX =",I_CX *1000,"[mA]\n")
print("U_CEX = U_cc -(I_CX * R_C) =", U_CEX,"[V]\n")


# 2)

k_uo = round(-gm * r_wy,2)
B = abs(k_uo * A)

print("2)")
print("B =", B, "V\n")


# 3)

k_u = round(k_uo * R_o / (R_o + r_wy),2)
B = abs(k_u * A)

print("3)")
print("B =", B, "V\n")

# 4)

R_BEI = R_BE * R_B / (R_BE + R_B)
k_ue = round(k_u * R_BEI / (R_BEI + R_g),2)

B = abs(k_ue * A)

print("4)")
print("B =", B, "V\n")











