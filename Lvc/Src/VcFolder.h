#ifndef _VcFolder_h_
#define _VcFolder_h_

#include "GSubProcess.h"

class ReaderThread : public LThread
{
	GStream *Out;
	GSubProcess *Process;

public:
	ReaderThread(GSubProcess *p, GStream *out);
	~ReaderThread();

	int Main();
};

class VcFolder : public GTreeItem
{
	struct ParseParams
	{
		GString Str;
	};

	typedef bool (VcFolder::*ParseFn)(int, GString, ParseParams*);
	
	struct Cmd : public GStream
	{
		GStringPipe Buf;
		GStream *Log;
		GAutoPtr<LThread> Rd;
		ParseFn PostOp;
		GString Param;

		Cmd(GStream *log)
		{
			Log = log;
		}

		ssize_t Write(const void *Ptr, ssize_t Size, int Flags = 0)
		{
			ssize_t Wr = Buf.Write(Ptr, Size, Flags);
			if (Log) Log->Write(Ptr, Size, Flags);
			return Wr;
		}
	};

	class UncommitedItem : public LListItem
	{
		AppPriv *d;

	public:
		UncommitedItem(AppPriv *priv)
		{
			d = priv;
		}

		void OnPaint(GItem::ItemPaintCtx &Ctx);
		void Select(bool b);
	};

	AppPriv *d;
	VersionCtrl Type;
	GString Path, CurrentCommit, RepoUrl;
	GArray<VcCommit*> Log;
	GString CurrentBranch;
	GString::Array Branches;
	GAutoPtr<UncommitedItem> Uncommit;
	GString Cache, NewRev;
	bool CommitListDirty;
	int Unpushed, Unpulled;
	GString CountCache;
	GTreeItem *Tmp;
	
	GArray<Cmd*> Cmds;
	bool IsLogging, IsGetCur, IsUpdate, IsFilesCmd, IsWorkingFld, IsCommit, IsUpdatingCounts;

	void Init(AppPriv *priv);
	const char *GetVcName();
	bool StartCmd(const char *Args, ParseFn Parser, GString Param = GString(), bool LogCmd = false);
	void OnBranchesChange();

	bool ParseDiffs(GString s, GString Rev, bool IsWorking);
	bool ParseLog(int Result, GString s, ParseParams *Params);
	bool ParseInfo(int Result, GString s, ParseParams *Params);
	bool ParseFiles(int Result, GString s, ParseParams *Params);
	bool ParseWorking(int Result, GString s, ParseParams *Params);
	bool ParseUpdate(int Result, GString s, ParseParams *Params);
	bool ParseCommit(int Result, GString s, ParseParams *Params);
	bool ParsePush(int Result, GString s, ParseParams *Params);
	bool ParsePull(int Result, GString s, ParseParams *Params);
	bool ParseCounts(int Result, GString s, ParseParams *Params);
	bool ParseRevert(int Result, GString s, ParseParams *Params);
	bool ParseBlame(int Result, GString s, ParseParams *Params);
	bool ParseSaveAs(int Result, GString s, ParseParams *Params);
	bool ParseBranches(int Result, GString s, ParseParams *Params);
	
public:
	VcFolder(AppPriv *priv, const char *p);
	VcFolder(AppPriv *priv, GXmlTag *t);

	VersionCtrl GetType();
	AppPriv *GetPriv() { return d; }
	const char *GetPath() { return Path; }
	char *GetText(int Col);
	bool Serialize(GXmlTag *t, bool Write);
	GXmlTag *Save();
	void Select(bool b);
	void ListCommit(const char *Rev);
	void ListWorkingFolder();
	void Commit(const char *Msg, const char *Branch, bool AndPush);
	void Push();
	void Pull();
	bool Revert(const char *Path, const char *Revision = NULL);
	bool Blame(const char *Path);
	bool SaveFileAs(const char *Path, const char *Revision);
	void ReadDir(GTreeItem *Parent, const char *Path);

	void OnPulse();
	void OnUpdate(const char *Rev);
	void OnMouseClick(GMouse &m);
	void OnRemove();
	void OnExpand(bool b);
};

#endif