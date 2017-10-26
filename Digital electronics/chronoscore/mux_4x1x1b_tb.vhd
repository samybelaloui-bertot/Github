--------------------------------------------------------------------------------
-- Company: 
-- Engineer:
--
-- Create Date:   10:47:39 02/16/2016
-- Design Name:   
-- Module Name:   C:/CPE_users/TP_ELN2/Groupe D/BELALOUI-CHAVRET/Projet1/chronoscore/mux_4x1x1b_tb.vhd
-- Project Name:  chronoscore
-- Target Device:  
-- Tool versions:  
-- Description:   
-- 
-- VHDL Test Bench Created by ISE for module: mux_4x1x1b
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
 
ENTITY mux_4x1x1b_tb IS
END mux_4x1x1b_tb;
 
ARCHITECTURE behavior OF mux_4x1x1b_tb IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT mux_4x1x1b
    PORT(
         A : IN  std_logic;
         B : IN  std_logic;
         C : IN  std_logic;
         D : IN  std_logic;
         sel : IN  std_logic_vector(1 downto 0);
         O : OUT  std_logic
        );
    END COMPONENT;
    

   --Inputs
   signal A : std_logic := '0';
   signal B : std_logic := '0';
   signal C : std_logic := '0';
   signal D : std_logic := '0';
   signal sel : std_logic_vector(1 downto 0) := (others => '0');

 	--Outputs
   signal O : std_logic;
  
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: mux_4x1x1b PORT MAP (
          A => A,
          B => B,
          C => C,
          D => D,
          sel => sel,
          O => O
        );

   sel <="00" after 0 ns,
	"01" after 20 ns,
	"10" after 40 ns,
	"11" after 60 ns;
	
	A <= '1' after 0 ns;
	B <= '0' after 20 ns;
	C <= '1' after 40 ns;
	D <= '1' after 60 ns;
	
	
END;
