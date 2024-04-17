#include "morse.h"

const long dit_time   = 180u;
const long dah_time   = dit_time * 4;
const long gap_time   = dit_time * 1;
const long ch_time    = dit_time * 4;
const long word_time  = dit_time * 6;

const int m_codes[] =
        { 0b01,     2,    // A
          0b1000,   4,    // B
          0b1010,   4,    // C
          0b100,    3,    // D
          0b0,      1,    // E
          0b0010,   4,    // F
          0b110,    3,    // G
          0b0000,   4,    // H
          0b00,     2,    // I
          0b0111,   4,    // J
          0b101,    3,    // K
          0b0100,   4,    // L
          0b11,     2,    // M
          0b10,     2,    // N
          0b111,    3,    // O
          0b0110,   4,    // P
          0b1101,   4,    // Q
          0b010,    3,    // R
          0b000,    3,    // S
          0b1,      1,    // T
          0b001,    3,    // U
          0b0001,   4,    // V
          0b011,    3,    // W
          0b1001,   4,    // X
          0b1011,   4,    // Y
          0b1100,   4,    // Z
          0b11111,  5,    // Zero
          0b01111,  5,    // One
          0b00111,  5,    // Two
          0b00011,  5,    // Three
          0b00001,  5,    // Four
          0b00000,  5,    // Five
          0b10000,  5,    // Six
          0b11000,  5,    // Seven
          0b11100,  5,    // Eight
          0b11110,  5,    // Nine
          0b010101, 6,    // Full Stop
          0b110011, 6,    // Comma
          0b111000, 6,    // Colon
          0b001100, 6,    // Question Mark
          0b011110, 6,    // Apostrophe
          0b100001, 6,    // Hyphen
          0b10010,  5,    // Slash
          0b010010, 6,    // Quotation Marks
          0b011010, 6,    // @
          0b10001,  5 };  // Equals

const char codelist[]=
          "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789.,:?'-/\"@=";



int strplace( char * s1, char s2 )
{
  int s1_place = 0;

  if( ( s1 == 0 ) || ( s2 == 0 ) ) return 255;

  if(  !strlen( s1 ) ) return 255;

  do
  {
    if ( *s1 == s2 ) return s1_place;

    s1++;
    s1_place++;

  } while( *s1 != 0 );

  return 255;
}



int Morse_putc( char m_ch )
{
  int morse_LUV;
  int codelen;
  int m_code;
  int target_bit;

  if( m_ch == ' ' )
  {
    Delay_Ticks( word_time );
    return m_ch;
  }

  m_ch = toupper( m_ch );

  morse_LUV = strplace( codelist, m_ch );
  if( morse_LUV == 255 ) return 0;

  m_code = m_codes[ morse_LUV << 1 ];
  codelen = m_codes[ ( morse_LUV << 1 ) + 1];

  target_bit = 1 << ( codelen - 1 );

  for( ; codelen !=0; codelen-- )
  {
    beeping = 1;

    if( m_code & target_bit )
      Delay_Ticks( dah_time );
    else
      Delay_Ticks( dit_time );

    beeping = 0;

    Delay_Ticks( gap_time );

    target_bit = target_bit >> 1;
  }

  Delay_Ticks( ch_time );

  return m_ch;
}

int Morse_puts( char * m_str )
{
  if( m_str == 0 ) return 0;

  for( ; *m_str != 0; m_str++ )
    Morse_putc( *m_str );

  return 1;
}