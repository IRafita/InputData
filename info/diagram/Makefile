all: isFuntionOrOpenParentesis isDigit isArgumentSeparator isOperator
isFuntionOrOpenParentesis:
	pic src/isFuntionOrOpenParentesis.tr | groff > isFuntionOrOpenParentesis.ps
	rm eps/isFuntionOrOpenParentesis.eps -f
	ps2eps isFuntionOrOpenParentesis.ps
	rm isFuntionOrOpenParentesis.ps
	mv isFuntionOrOpenParentesis.eps eps
isDigit:
	pic src/isDigit.tr | groff > isDigit.ps
	rm eps/isDigit.eps -f
	ps2eps isDigit.ps
	rm isDigit.ps
	mv isDigit.eps eps
isArgumentSeparator:
	pic src/isArgumentSeparator.tr | groff > isArgumentSeparator.ps
	rm eps/isArgumentSeparator.eps -f
	ps2eps isArgumentSeparator.ps
	rm isArgumentSeparator.ps
	mv isArgumentSeparator.eps eps
isOperator:
	pic src/isOperator.tr | groff > isOperator.ps
	rm eps/isOperator.eps -f
	ps2eps isOperator.ps
	rm isOperator.ps
	mv isOperator.eps eps
