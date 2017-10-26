--------------------------------------------------------------------------------
-- Company: 
-- Engineer:
--
-- Create Date:   22:29:06 02/25/2016
-- Design Name:   
-- Module Name:   C:/Users/samyb/Documents/CPE/Electronique/Projet1/chronoscore/register_4b_tb.vhd
-- Project Name:  chronoscore
-- Target Device:  
-- Tool versions:  
-- Description:   
-- 
-- VHDL Test Bench Created by ISE for module: register_4b
-- 
-- Dependencies:
-- 
-- Revision:
-- Revision 0.01 - File Created
-- Additional Comments:
--
-- Notes: 
-- This testbench has been automatically generated using types std_logic and
-- std_logic_vector for the ports of the unit under test.  Xilinx recommends
-- that these types always be used for the top-level I/O of a design in order
-- to guarantee that the testbench will bind correctly to the post-implementation 
-- simulation model.
--------------------------------------------------------------------------------
LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
 
-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--USE ieee.numeric_std.ALL;
 
ENTITY register_4b_tb IS
END register_4b_tb;
 
ARCHITECTURE behavior OF register_4b_tb IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT register_4b
    PORT(
         D : IN  std_logic_vector(3 downto 0);
         clk : IN  std_logic;
         Q : OUT  std_logic_vector(3 downto 0)
        );
    END COMPONENT;
    

   --Inputs
   signal D : std_logic_vector(3 downto 0) := (others => '0');
   signal clk : std_logic := '0';

 	--Outputs
   signal Q : std_logic_vector(3 downto 0);

   -- Clock period definitions
   constant clk_period : time := 10 ns;
 
BEGIN
	
	D <="0001" after 0 ns,
	"0010" after 40 ns,
	"0011" after 60 ns,
	"0100" after 80 ns,
	"0101" after 100 ns,
	"0110" after 120 ns,
	"0111" after 140 ns,
	"1000" after 160 ns,
	"1001" after 180 ns,
	"1010" after 200 ns,
	"1011" after 220 ns,
	"1100" after 240 ns,
	"1101" after 260 ns,
	"1110" after 280 ns,
	"1111" after 300 ns;
 
	-- Instantiate the Unit Under Test (UUT)
   uut: register_4b PORT MAP (
          D => D,
          clk => clk,
          Q => Q
        );

   -- Clock process definitions
   clk_process :process
   begin
		clk <= '0';
		wait for clk_period/2;
		clk <= '1';
		wait for clk_period/2;
   end process;
 

   -- Stimulus process
   stim_proc: process
   begin		
      -- hold reset state for 100 ns.
      wait for 100 ns;	

      wait for clk_period*10;

      -- insert stimulus here 

      wait;
   end process;

END;
