# Skrypt liczący prąd, napięcie i moc w obwodzie z diodą oraz rezystorem
import math

E = float(input("Enter the voltage (E): "))
print(f"E = {E} V")

R = float(input("Enter the resistance (R): "))
print(f"R = {R} Ω")

R_0 = float(input("Enter the load resistance (R_0): "))
print(f"R_0 = {R_0} Ω")

U_D0 = float(input("Enter the diode voltage drop (U_D0): "))
print(f"U_D0 = {U_D0} V")

r_D = float(input("Enter the diode resistance (rD): "))
print(f"rD = {r_D} Ω")

Ix = round((E - U_D0) / (R + r_D), 4)
Rx = round((R * r_D) / (R + r_D), 4)
Ux = round(Ix * r_D + U_D0, 4)

print(f"The current is: {Ix} A")
print(f"The voltage is: {Ux} V")
print(f"The resistance is: {Rx} Ω")

U_D = round(Ux * R_0 / (Rx + R_0), 4)
print(f"The voltage drop across the diode is: {U_D} V")

I_D = round((U_D - U_D0) / r_D, 4)
print(f"The current through the diode is: {I_D} A")

P_D = round(I_D * U_D, 4)
if P_D < 0:
    P_D = 0
    print("The power dissipated in the diode is negative. Setting to 0.")
    print(f"The power dissipated in the diode is: {P_D} W")
else:
    print(f"The power dissipated in the diode is: {P_D} W")

