# moc maksymalna dobór R minimalnego
import math

E = float(input("Enter the voltage (E): "))
print(f"E = {E} V")

R_0 = float(input("Enter the load resistance (R_0): "))
print(f"R_0 = {R_0} Ω")

U_D0 = float(input("Enter the diode voltage drop (U_D0): "))
print(f"U_D0 = {U_D0} V")

r_D = float(input("Enter the diode resistance (rD): "))
print(f"rD = {r_D} Ω")

P_MAX = float(input("Enter the maximum power (P_MAX) in Wats: "))
print(f"P_MAX = {P_MAX} W")

I_DMAX = round(P_MAX / U_D0, 4)
print(f"I_DMAX = {I_DMAX} A")

U_D = round(I_DMAX * r_D + U_D0, 4)
print(f"U_D = {U_D} V")

I_0 = round(U_D / R_0, 4)
print(f"I_0 = {I_0} A")

I = round(I_0 + I_DMAX, 4)
print(f"I = {I} A")

U_R = round(E - U_D, 4)
print(f"U_R = {U_R} V")

R = round(U_R / I, 4)
print(f"R = {R} Ω")

I_D = 0
U_D = U_D0
print(f"U_D = {U_D} V")
I = (E - U_D) / R
print(f"I = {I} A")
R_min = round((U_D) / I, 4)
print(f"R_min = {R_min} Ω")