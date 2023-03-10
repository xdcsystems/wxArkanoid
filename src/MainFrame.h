#pragma once

// Forward declarations
class Timer;
class RenderWindow;
class MediaManager;

namespace ControlPanel
{
    class Panel;
}

class MainFrame final : public wxFrame
{
    public:
        MainFrame() = default;

        MainFrame(
            wxWindow* parent,
            int id = wxID_ANY,
            wxString title = wxTheApp->GetAppName(),
            wxPoint pos = wxDefaultPosition,
            wxSize size = { 1024, 768 },
            int style = ( wxDEFAULT_FRAME_STYLE | wxTAB_TRAVERSAL | wxCLIP_CHILDREN ) & ~( wxRESIZE_BORDER | wxMAXIMIZE_BOX ) );

        bool Create(
            wxWindow* parent,
            int id = wxID_ANY,
            wxString title = wxTheApp->GetAppName(),
            wxPoint pos = wxDefaultPosition,
            wxSize size = { 1024, 768 },
            int style = ( wxDEFAULT_FRAME_STYLE | wxTAB_TRAVERSAL | wxCLIP_CHILDREN ) & ~( wxRESIZE_BORDER | wxMAXIMIZE_BOX ),
            const wxString& name = wxASCII_STR( wxFrameNameStr ) );

        ~MainFrame();

        void render( wxIdleEvent& );
        bool isRunning() const { return m_isRunning; };
        void start();
        void stop();

    private:
        // Event Handlers
        void OnClose( wxCloseEvent& );
        void OnLaunchPressed( wxCommandEvent& );
        void OnRoundStarted( wxCommandEvent& );
        void OnRoundCompleted( wxCommandEvent& );
        void OnBallLost( wxCommandEvent& );
        void OnScoreIncreased( wxCommandEvent& );
        void OnVideoFinished( wxCommandEvent& );

        // Helper functions
        void init();

    private:
        // Private data
        std::shared_ptr<RenderWindow> m_renderSurface;
        std::shared_ptr<ControlPanel::Panel> m_controlPanel;
        std::shared_ptr <MediaManager> m_mediaManager;
        std::shared_ptr<Timer> m_timer;

        bool m_isRunning = false;

        DECLARE_EVENT_TABLE()
};
