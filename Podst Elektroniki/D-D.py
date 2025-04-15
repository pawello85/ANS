# Skrypt do obliczania prądu i napięcia w obwodzie z dwoma diodami
import math

E = float(input("Enter the voltage (E): "))
print(f"E = {E} V")

R = float(input("Enter the resistance (R): "))
print(f"R = {R} Ω")

U_D01 = float(input("Enter the diode voltage drop (U_D01): "))
print(f"U_D01 = {U_D01} V")

r_D1 = float(input("Enter the diode resistance (r_D1): "))
print(f"r_D1 = {r_D1} Ω")

U_D02 = float(input("Enter the diode voltage drop (U_D02): "))
print(f"U_D02 = {U_D02} V")

r_D2 = float(input("Enter the diode resistance (r_D2): "))
print(f"r_D2 = {r_D2} Ω")

I_D1 = round((E - U_D01) / (R + r_D1), 4)
U_D1 = round(I_D1 * r_D1 + U_D01, 4)
P_D1 = round(I_D1 * U_D1, 4)

print(f"The current through the first diode is: {I_D1} A")
print(f"The voltage across the first diode is: {U_D1} V")

if P_D1 < 0:
    P_D1 = 0
    print("The power dissipated in the diode is negative. Setting to 0.")
    print(f"The power dissipated in the diode is: {P_D1} W")
else:
    print(f"The power dissipated in the diode is: {P_D1} W")

print("W = ON")

I_D2 = round((E - U_D02) / (R + r_D2), 4)
U_D2 = round(I_D2 * r_D2 + U_D02, 4)
P_D2 = round(I_D2 * U_D2, 4)

print(f"The current through the second diode is: {I_D2} A")
print(f"The voltage across the second diode is: {U_D2} V")
if P_D2 < 0:
    P_D2 = 0
    print("The power dissipated in the diode is negative. Setting to 0.")
    print(f"The power dissipated in the diode is: {P_D2} W")
else:
    print(f"The power dissipated in the diode is: {P_D2} W")

U_D1 = U_D2
I_D1 = (U_D2 - U_D01) / r_D1
if I_D1 < 0:
    P_D1 = 0
    print("The current through the first diode is negative. Setting to 0.")
    print(f"Power on first diode is(P_D1): {P_D1} W")