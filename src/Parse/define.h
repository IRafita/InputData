typedef struct
{
	enum
	{
		operand				= 0b000,
		digit				= 0b001,
		argumentSeparator		= 0b010,
		closeParentesis			= 0b011,
		functionANDopenParentesis	= 0b100,
		function			= 0b101,
		openParentesis			= 0b110,
	} statToken;
	char *content;
} Token;
