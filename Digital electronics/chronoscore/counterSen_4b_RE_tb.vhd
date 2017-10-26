--------------------------------------------------------------------------------
-- Company: 
-- Engineer:
--
-- Create Date:   21:53:34 02/26/2016
-- Design Name:   
-- Module Name:   C:/Users/samyb/Documents/CPE/Electronique/Projet1/chronoscore/counterSen_4b_RE_tb.vhd
-- Project Name:  chronoscore
-- Target Device:  
-- Tool versions:  
-- Description:   
-- 
-- VHDL Test Bench Created by ISE for module: counterSen_4b_RE
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
 
ENTITY counterSen_4b_RE_tb IS
END counterSen_4b_RE_tb;
 
ARCHITECTURE behavior OF counterSen_4b_RE_tb IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT counterSen_4b_RE
    PORT(
         CE : IN  std_logic;
         R : IN  std_logic;
         clk : IN  std_logic;
         Q : OUT  std_logic_vector(3 downto 0);
         TC : OUT  std_logic
        );
    END COMPONENT;
    

   --Inputs
   signal CE : std_logic := '0';
   signal R : std_logic := '0';
   signal clk : std_logic := '0';

 	--Outputs
   signal Q : std_logic_vector(3 downto 0);
   signal TC : std_logic;

   -- Clock period definitions
   constant clk_period : time := 10 ns;
 
BEGIN

R <= '1' after 40 ns,
	'0' after 70 ns;
	
CE <= '0' after 0 ns,
		'1' after 10 ns;
 
	-- Instantiate the Unit Under Test (UUT)
   uut: counterSen_4b_RE PORT MAP (
          CE => CE,
          R => R,
          clk => clk,
          Q => Q,
          TC => TC
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
