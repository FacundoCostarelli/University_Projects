library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.NUMERIC_STD.ALL;

entity miniAlu_tb_con_test_cases is
Generic (N: integer := 4);
end miniAlu_tb_con_test_cases;

architecture Behavioral of miniAlu_tb_con_test_cases is
component miniAlu is
Generic (DATA_BITS: integer := 4);
port ( a: in std_logic_vector (DATA_BITS-1 downto 0);
       b: in std_logic_vector (DATA_BITS-1 downto 0); 
       carryIn : in std_logic;
       carryOut : out std_logic;
       res: out std_logic_vector (DATA_BITS-1 downto 0); 
       sat: in std_logic;        
       code: in std_logic_vector (3 downto 0);        
       zero : out std_logic;
       overflow : out std_logic;
       negative : out std_logic
);
end component;

    type TState is (reset,Prueba_AND,Prueba_OR,Prueba_XOR,Prueba_SumaSimple,Prueba_SumaGeneraCarryOut,Prueba_SumaConCarryIn,
    Prueba_SumaConOverflow,Prueba_SumaConOverflowYSat,Prueba_RestaSimple,Prueba_RestaConBorrowIn,Prueba_RestaConOverflow,
    Prueba_RestaConOverflowYSat);
    
    signal StateProob: Tstate := reset;
    signal code: std_logic_vector (3 downto 0);        
    signal a :std_logic_vector (N-1 downto 0);
    signal b : std_logic_vector (N-1 downto 0);
    signal carryIn : std_logic;
    signal sat: std_logic;        
    -- salidas
    signal res: std_logic_vector (N-1 downto 0); 
    signal carryOut : std_logic;
    signal zero : std_logic;
    signal overflow : std_logic;
    signal negative : std_logic;
    -- salidas esperadas
    signal res_esperado: std_logic_vector (N-1 downto 0):=(others=>'0');
    signal carry_esperado: std_logic:='0';
    signal zero_esperado: std_logic:='0';
    signal overflow_esperado: std_logic:='0';
    signal negative_esperado: std_logic:='0';
    -- verificacion
    signal test_ok : std_logic := '1';
    
begin

uut: miniAlu 
    Generic map (DATA_BITS => N)
    PORT MAP (a => a,
              b => b,
              carryIn => carryIn,
              carryOut => carryOut,
              res => res, 
              sat => sat,        
              code => code,        
              zero => zero,
              overflow => overflow,
              negative => negative);

stim_proc: process
begin
	sat <= '0';
	carryIn <= '0';
	code <= "0000";
    
    res_esperado<=X"0";
    carry_esperado<='-';
    zero_esperado<='-';
    overflow_esperado<='-';
    negative_esperado<='-';

    test_ok <= '-';
    
	-- AND --
	code <= "0000";
	StateProob <= Prueba_AND;
	b <= X"F"; a <= X"A"; res_esperado<=X"A" ; zero_esperado<='0'; 
	wait for 1 ns;
	if(res=res_esperado and zero=zero_esperado) then
        test_ok<='1';
	else
        test_ok<='X';
	end if;
	wait for 99 ns;
	
	b <= X"5"; a <= X"A"; res_esperado<=X"0" ; zero_esperado<='1';
	wait for 1 ns;
	if(res=res_esperado and zero=zero_esperado) then
        test_ok<='1';
	else
        test_ok<='X';
	end if;
	wait for 99 ns;
	
	b <= X"5"; a <= X"3"; res_esperado<=X"1" ; zero_esperado<='0'; 
		wait for 1 ns;
	if(res=res_esperado and zero=zero_esperado) then
        test_ok<='1';
	else
        test_ok<='X';
	end if;
	wait for 99 ns;

    
    -- or --
	code <= "0001";
	StateProob <= Prueba_OR;
	b <= X"F"; a <= X"A"; res_esperado<=X"F" ; zero_esperado<='0'; 
	wait for 1 ns;
	if(res=res_esperado and zero=zero_esperado) then
        test_ok<='1';
	else
        test_ok<='X';
	end if;
	wait for 99 ns;

	b <= X"5"; a <= X"A"; res_esperado<=X"F" ; zero_esperado<='0';
	wait for 1 ns;
	if(res=res_esperado and zero=zero_esperado) then
        test_ok<='1';
	else
        test_ok<='X';
	end if;
	wait for 99 ns;

	b <= X"0"; a <= X"A"; res_esperado<=X"A" ; zero_esperado<='0';
	wait for 1 ns;
	if(res=res_esperado and zero=zero_esperado) then
        test_ok<='1';
	else
        test_ok<='X';
	end if;
	wait for 99 ns;

    zero_esperado<='-';
    
--    -- xor --
	code <= "0010";
	StateProob <= Prueba_XOR;
	b <= X"F"; a <= X"A"; res_esperado<=X"5" ; zero_esperado<='0'; 
	if(res=res_esperado and zero=zero_esperado) then
        test_ok<='1';
	else
        test_ok<='X';
	end if;
	wait for 99 ns;
	
	b <= X"5"; a <= X"A"; res_esperado<=X"F" ; zero_esperado<='0'; 
	if(res=res_esperado and zero=zero_esperado) then
        test_ok<='1';
	else
        test_ok<='X';
	end if;
	wait for 99 ns;
	
	b <= X"0"; a <= X"A"; res_esperado<=X"A" ; zero_esperado<='0'; 
	if(res=res_esperado and zero=zero_esperado) then
        test_ok<='1';
	else
        test_ok<='X';
	end if;
	wait for 99 ns;
	
    carry_esperado<='-';
    zero_esperado<='-';
    zero_esperado<='-';
    overflow_esperado<='-';
    negative_esperado<='-';
    
    -- Suma --
    code <= "0011"; sat <= '0'; -- A + B

    StateProob <= Prueba_SumaSimple;
    carryIn <= '0'; a <= X"1"; b <= X"1"; --  1 + 1
    res_esperado<=X"2"; carry_esperado<='0'; zero_esperado<='0' ;overflow_esperado<='0'; negative_esperado<='0';  
    wait for 1 ns;
    if( res=res_esperado and
        carryOut=carry_esperado and
        zero=zero_esperado and
        overflow_esperado=overflow and
        negative_esperado=negative) then
        test_ok<='1';
	else
        test_ok<='X';
	end if;
    wait for 99 ns;   

    StateProob <= Prueba_SumaGeneraCarryOut; -- -1 + -1 (Carry)
	carryIn <= '0'; a <= X"F"; b <= X"F";  
	res_esperado<=X"E"; carry_esperado<='1'; zero_esperado<='0' ;overflow_esperado<='0'; negative_esperado<='1';  
    wait for 1 ns;
    if( res=res_esperado and
        carryOut=carry_esperado and
        zero=zero_esperado and
        overflow_esperado=overflow and
        negative_esperado=negative) then
        test_ok<='1';
	else
        test_ok<='X';
	end if;
    wait for 99 ns;   

    StateProob <= Prueba_SumaConCarryIn;
    carryIn <= '1'; a <= X"0"; b <= X"0";   --  0 + 0
    res_esperado<=X"1"; carry_esperado<='0'; zero_esperado<='0' ;overflow_esperado<='0'; negative_esperado<='0';     
    wait for 1 ns;
    if( res=res_esperado and
        carryOut=carry_esperado and
        zero=zero_esperado and
        overflow_esperado=overflow and
        negative_esperado=negative) then
        test_ok<='1';
	else
        test_ok<='X';
	end if;
    wait for 99 ns;   
    
    StateProob <= Prueba_SumaConOverflow;
	carryIn <= '0'; a <= X"1"; b <= X"7";  --  1 + 7 (overflow)
    res_esperado<=X"8"; carry_esperado<='0'; zero_esperado<='0' ;overflow_esperado<='1'; negative_esperado<='1';     
    wait for 1 ns;
    if( res=res_esperado and
        carryOut=carry_esperado and
        zero=zero_esperado and
        overflow_esperado=overflow and
        negative_esperado=negative) then
        test_ok<='1';
	else
        test_ok<='X';
	end if;
    wait for 99 ns;   
    
    StateProob <= Prueba_SumaConOverflowYSat;
    sat <= '1'; carryIn <= '0'; a <= X"1"; b <= X"7";  --  1 + 7 (overflow, sat )
    res_esperado<=X"7"; carry_esperado<='0'; zero_esperado<='0' ;overflow_esperado<='1'; negative_esperado<='0';     
    wait for 1 ns;
    if( res=res_esperado and
        carryOut=carry_esperado and
        zero=zero_esperado and
        overflow_esperado=overflow and
        negative_esperado=negative) then
        test_ok<='1';
	else
        test_ok<='X';
	end if;
    wait for 99 ns;   

    carry_esperado<='-';
    zero_esperado<='-';
    overflow_esperado<='-';
    negative_esperado<='-';
        
    -- Resta --
    code <= "0100"; sat <= '0'; -- A - B
    StateProob <= Prueba_RestaSimple;
    carryIn <= '0'; a <= X"0"; b <= X"1";  --   0 - 1 = F (borrow)
    res_esperado<=X"F"; carry_esperado<='1'; zero_esperado<='0' ;overflow_esperado<='0'; negative_esperado<='1';     
    wait for 1 ns;
    if( res=res_esperado and
        carryOut=carry_esperado and
        zero=zero_esperado and
        overflow_esperado=overflow and
        negative_esperado=negative) then
        test_ok<='1';
	else
        test_ok<='X';
	end if;
    wait for 99 ns;   
    
    StateProob <= Prueba_RestaConBorrowIn;
	carryIn <= '1'; a <= X"1"; b <= X"0"; --   1 - 0 -1(Cin) = -2 (Carry)
    res_esperado<=X"0"; carry_esperado<='0'; zero_esperado<='1' ;overflow_esperado<='0'; negative_esperado<='0';     
    wait for 1 ns;
    if( res=res_esperado and
        carryOut=carry_esperado and
        zero=zero_esperado and
        overflow_esperado=overflow and
        negative_esperado=negative) then
        test_ok<='1';
	else
        test_ok<='X';
	end if;
    wait for 99 ns;   
    
    StateProob <= Prueba_RestaConOverflow;
	carryIn <= '0'; a <= X"8"; b <= X"1"; --  -8 - 1 (overflow) 
    res_esperado<=X"7"; carry_esperado<='0'; zero_esperado<='0' ;overflow_esperado<='1'; negative_esperado<='0';     
    wait for 1 ns;
    if( res=res_esperado and
        carryOut=carry_esperado and
        zero=zero_esperado and
        overflow_esperado=overflow and
        negative_esperado=negative) then
        test_ok<='1';
	else
        test_ok<='X';
	end if;
    wait for 99 ns;   
    
    StateProob <= Prueba_RestaConOverflow;
	carryIn <= '0'; a <= X"7"; b <= X"F"; --   7 - -1 (overflow)
    res_esperado<=X"8"; carry_esperado<='1'; zero_esperado<='0' ;overflow_esperado<='1'; negative_esperado<='1';     
    wait for 1 ns;
    if( res=res_esperado and
        carryOut=carry_esperado and
        zero=zero_esperado and
        overflow_esperado=overflow and
        negative_esperado=negative) then
        test_ok<='1';
	else
        test_ok<='X';
	end if;
    wait for 99 ns;   

    StateProob <= Prueba_RestaConOverflowYSat;
    sat <= '1'; carryIn <= '0'; a <= X"7"; b <= X"F"; --  7 - -1 (overflow, sat)  
    res_esperado<=X"7"; carry_esperado<='1'; zero_esperado<='0' ;overflow_esperado<='1'; negative_esperado<='0';     
    wait for 1 ns;
    if( res=res_esperado and
        carryOut=carry_esperado and
        zero=zero_esperado and
        overflow_esperado=overflow and
        negative_esperado=negative) then
        test_ok<='1';
	else
        test_ok<='X';
	end if;
    wait for 99 ns;   
    
    wait;
    
end process;

end Behavioral;
