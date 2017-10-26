----------------------------------------------------------------------------------
-- 
-- Engineer:       Renaud DAVIOT
-- 
-- Create Date:    2016 
--
-- Module Name:    timer_1ms - Behavioral 
-- Project Name:   Chronoscore_VGA
--
-- Target Devices: XC3S200 (Spartan 3 - 200K)
-- 
-- Description: 
--
--
-- Revision 0.01 - File Created
--
----------------------------------------------------------------------------------

library IEEE;
    use IEEE.STD_LOGIC_1164.ALL;
    use IEEE.std_logic_arith.ALL;    -- Pour la conversion de donnees
    use IEEE.std_logic_unsigned.ALL; -- pour l operateur +

entity timer_1ms is
    Port ( CLK     : in   STD_LOGIC;
           T_out   : out  STD_LOGIC);
end timer_1ms;

architecture Behavioral of timer_1ms is

    constant DIV_VAL : INTEGER := 50000;  --> A décommenter pour la synthèse, à commenter pour la simulation
    --constant DIV_VAL : INTEGER := 5;        --> A commenter pour la synthèse, à décommenter pour la simulation
    
    
    signal   vcount   : INTEGER range 0 to DIV_VAL-1 := 0;   -- Limit size of vcount
   
begin

   process (CLK)
   begin
      if rising_edge(CLK) then
      
         vcount <= vcount + 1;
         
         if (vcount = DIV_VAL-1) then 
               vcount <= 0; -- INTEGER type
               T_out <= '1';
         else 
               T_out <= '0';
         end if;
         
      end if;
      
   end process;


end Behavioral;

