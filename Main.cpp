// inclui tipos báciso e funções da API Win32
#define WIN32_LEARN_AND_MEAN
#include <Windows.h>

// Protótipo do procedimento da janela
LRESULT CALLBACK WinProc(HWND, UINT, WPARAM, LPARAM);


// Iniciando a aplicação
int APIENTRY WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR IpCmdLine, _In_ int nCmdShow) {

	HWND		hwnd;		// identificador da janela
	MSG			msg;		// mensagem
	WNDCLASS	wndclass;	// classe da janela

	// definindo os paramentos de janela chamada "DefaultWindow"
	wndclass.style = CS_HREDRAW | CS_VREDRAW;
	wndclass.lpfnWndProc = WinProc;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.hInstance = hInstance;
	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndclass.hCursor = LoadIcon(NULL, IDC_ARROW);
	wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wndclass.lpszMenuName = NULL;
	wndclass.lpszClassName = "DefaultWindow";

	// Fazendo o registro da classe criada acima
	if (!RegisterClass(&wndclass)) {
		MessageBox(NULL, "Erro na criação da janela!", "Applicação", MB_ICONERROR);
		return 0;
	}

	// Criando a janela com base na classe criada
	hwnd = CreateWindow(
		"DefaultWindow",		// classe da janela
		"Aplicação",			// titulo da janela
		WS_OVERLAPPEDWINDOW,	// estilo da janela
		CW_USEDEFAULT,			// posição x inicial
		CW_USEDEFAULT,			// posição y inicial
		CW_USEDEFAULT,			// largura inicial
		CW_USEDEFAULT,			// altura inicial
		NULL,					// idendificador da janela pai
		NULL,					// idendificador do menu
		hInstance,				// idendificador da aplicação
		NULL,					// parâmetros de criação
		);

	// Mostra e atualizar a janela
	ShowWindow(hwnd, nCmdShow);
	UpdateWindow(hwnd);

	// Tratamento de mensagens destinadas a janela da aplicação
	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return int(msg.wParam);
}

// procedimento da janela

LRESULT CALLBACK WinProc(HWND hwnd, UINT message, WPARAM vParam, LPARAM lParam) {
	
	HDC			hdc;		// representa o dispositiovo gráfico
	PAINTSTRUCT ps;			// guarda região invalidada da janela
	RECT		rect;		// região retângular

	switch (message)
	{
	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);

		GetClientRect(hwnd, &rect);
		DrawText(hdc, "Olá! Tudo bom?", -1, &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);

		EndPaint(hwnd, &ps);
		return 0;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hwnd, message, vParam, lParam);

}
